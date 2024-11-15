#include "pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(1);
}

void	execute_command(char *cmd, char *envp[])
{
	char	**arr_cmd;
	char	*path;

	arr_cmd = ft_split(cmd, ' ');
	path = get_path(arr_cmd[0], envp);
	if (path == NULL)
	{
		ft_putstr_fd("Error: command not found\n", 2);
		free_2d_array(arr_cmd);
		exit(1);
	}
	if (execve(path, arr_cmd, envp) == -1)
	{
		ft_putstr_fd("Error on execve\n", 2);
		free_2d_array(arr_cmd);
		free(path);
		exit(1);
	}
}

void	first_child_process(int pipe_fd[], char *cmd[], char *envp[])
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

void	second_child_process(int pipe_fd[], char *cmd[], char *envp[])
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
