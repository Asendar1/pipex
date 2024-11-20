/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:12 by hassende          #+#    #+#             */
/*   Updated: 2024/11/20 15:27:27 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	**path;
	char	*path_str;

	i = 0;
	if ((access(cmd, F_OK) && access(cmd, X_OK)) == 0)
		return (cmd);
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		return (NULL);
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
