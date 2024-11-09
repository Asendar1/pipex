/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:43:57 by hassende          #+#    #+#             */
/*   Updated: 2024/09/12 13:24:10 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (*str)
	{
		write (1, str, 1);
		str++;
		i++;
	}
	return (i);
}

void	ft_putnbr(int n, int *prt_len)
{
	if (n == -2147483648)
	{
		*(prt_len) += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*(prt_len) += write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, prt_len);
		ft_putnbr(n % 10, prt_len);
	}
	if (n <= 9)
		*(prt_len) += ft_putchar(n + 48);
}

void	ft_unsigned(unsigned int n, int *prt_len)
{
	if (n > 9)
	{
		ft_unsigned(n / 10, prt_len);
		ft_unsigned(n % 10, prt_len);
	}
	if (n <= 9)
		*(prt_len) += ft_putchar(n + '0');
}
