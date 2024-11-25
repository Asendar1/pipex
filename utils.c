/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:12 by hassende          #+#    #+#             */
/*   Updated: 2024/11/24 15:14:51 by hassende         ###   ########.fr       */
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

static	char	*find_command(char *cmd, char **path)
{
	int		i;
	char	*path_str;
	char	*temp_str;

	i = 0;
	while (path[i])
	{
		temp_str = ft_strjoin(path[i], "/");
		if (!temp_str)
			return (NULL);
		path_str = ft_strjoin(temp_str, cmd);
		free(temp_str);
		if (!path_str)
			return (NULL);
		if (access(path_str, X_OK) == 0)
			return (path_str);
		free(path_str);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	**path;
	char	*path_str;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		return (NULL);
	path_str = find_command(cmd, path);
	free_2d_array(path);
	return (path_str);
}
