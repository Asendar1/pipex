/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:39:37 by hassende          #+#    #+#             */
/*   Updated: 2024/09/12 11:55:32 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

	//? cspdiuxX%
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		prt_len;

	prt_len = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
			check_specifier((++format), args, &prt_len);
		else
		{
			prt_len += ft_putchar(*format);
		}
		format++;
	}
	va_end (args);
	return (prt_len);
}
