#ifndef PIPEX_H
# define PIPEX_H

// System Libraries
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

// Custom Libraries
#include "libft/libft.h"

char	*get_path(char *cmd, char *envp[]);
void	free_2d_array(char **arr);

#endif
