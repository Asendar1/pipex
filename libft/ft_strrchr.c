/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:47:22 by hassende          #+#    #+#             */
/*   Updated: 2024/08/27 18:04:23 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	const char		*rtn;

	uc = (unsigned char) c;
	rtn = 0;
	while (*s != '\0')
	{
		if (*s == uc)
			rtn = s;
		s++;
	}
	if (uc == '\0')
		rtn = s;
	return ((char *)rtn);
}
