/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:38:34 by hassende          #+#    #+#             */
/*   Updated: 2024/09/12 13:56:53 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_hex(const char *format, va_list args, int *prt_len)
{
	unsigned long long int	i;

	if (*format == 'p')
	{
		i = va_arg(args, unsigned long long);
		if (i == 0)
		{
			*(prt_len) += write(1, "(nil)", 5);
			return ;
		}
		*(prt_len) += write (1, "0x", 2);
		ft_puthexa(i, prt_len);
	}
	if (*format == 'x')
	{
		ft_prthexa (va_arg(args, unsigned int), 0, prt_len);
	}
	if (*format == 'X')
	{
		ft_prthexa (va_arg(args, unsigned int), 1, prt_len);
	}
	(void) i;
}

void	check_specifier(const char *format, va_list args, int *prt_len)
{
	if (*format == 'c')
		*(prt_len) += ft_putchar(va_arg(args, int));
	if (*format == 's')
		*(prt_len) += ft_putstr(va_arg(args, char *));
	if (*format == 'u')
		ft_unsigned (va_arg(args, unsigned int), prt_len);
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), prt_len);
	if (*format == 'p' || *format == 'x' || *format == 'X')
		check_hex(format, args, prt_len);
	if (*format == '%')
		*(prt_len) += write (1, "%", 1);
}
