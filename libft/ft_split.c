/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:48:57 by hassende          #+#    #+#             */
/*   Updated: 2024/08/27 14:06:35 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_nbr(const char *s, char c)
{
	int	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**rtn;
	int		i;
	int		len;

	rtn = (char **)malloc((word_nbr(s, c) + 1) * (sizeof(char *)));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			rtn[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	rtn[i] = NULL;
	return (rtn);
}
