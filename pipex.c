#include "pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(1);
}

void	execute_command(const char *cmd, char *const envp[])
{
	char *const	argv[] = {"/bin/sh", "-c", (char *)cmd, NULL};

	execve("/bin/sh", argv, envp);
	error_exit("Error on execve");
}

void	first_child_process(int pipe_fd[], char *cmd[], char *const envp[])
{
	int		fd;

	fd = open(cmd[1], O_RDONLY);
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	close(fd);
	close(pipe_fd[1]);
	execute_command(cmd[2], envp);
}

void	second_child_process(int pipe_fd[], char *cmd[], char *const envp[])
{
	int	fd;

	fd = open(cmd[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(pipe_fd[0], 0);
	dup2(fd, 1);
	close(pipe_fd[1]);
	close(fd);
	close(pipe_fd[0]);
	execute_command(cmd[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(pipe_fd) < 0)
		error_exit("Error on pipe");
	pid1 = fork();
	if (pid1 < 0)
		error_exit("Error on fork");
	if (pid1 == 0)
		first_child_process(pipe_fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("Error on fork");
	if (pid2 == 0)
		second_child_process(pipe_fd, argv, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
