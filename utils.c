#include "pipex.h"

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// TODO: you if no infile is there the program waits, remove exit from first child, check read mode in file in first child

char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	**path;
	char	*path_str;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	if(!path)
		error_exit("Error On split\n function returned NULL");
	i = 0;
	while (path[i])
	{
		path_str = ft_strjoin(path[i], "/");
		path_str = ft_strjoin(path_str, cmd);
		if (access(path_str, F_OK) == 0)
		{
			free_2d_array(path);
			return (path_str);
		}
		free(path_str);
		i++;
	}
	free_2d_array(path);
	return (NULL);
}
