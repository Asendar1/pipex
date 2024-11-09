/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:29:14 by hassende          #+#    #+#             */
/*   Updated: 2024/08/26 10:44:17 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	while (*str)
	{
		if (*str == (char)n)
			return ((char *)str);
		str++;
	}
	if (*str == (char)n)
		return ((char *)str);
	return (0);
}
