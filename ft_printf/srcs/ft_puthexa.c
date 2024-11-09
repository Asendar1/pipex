/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:27:17 by hassende          #+#    #+#             */
/*   Updated: 2024/09/12 13:50:23 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_lower_digits(char *digits);
void	init_upper_digits(char *digits);

void	ft_puthexa(unsigned long long int n, int *prt_len)
{
	char	lower_digits[16];

	init_lower_digits(lower_digits);
	if (n >= 16)
		ft_puthexa(n / 16, prt_len);
	*(prt_len) += write(1, &lower_digits[n % 16], 1);
}

void	ft_prthexa(unsigned int n, int uppercase, int *prt_len)
{
	char	lower_digits[16];
	char	upper_digits[16];

	init_lower_digits(lower_digits);
	init_upper_digits(upper_digits);
	if (n >= 16)
	{
		ft_prthexa(n / 16, uppercase, prt_len);
	}
	if (uppercase == 1)
	{
		*(prt_len) += write(1, &upper_digits[n % 16], 1);
	}
	else
	{
		*(prt_len) += write(1, &lower_digits[n % 16], 1);
	}
}

void	init_lower_digits(char *digits)
{
	digits[0] = '0';
	digits[1] = '1';
	digits[2] = '2';
	digits[3] = '3';
	digits[4] = '4';
	digits[5] = '5';
	digits[6] = '6';
	digits[7] = '7';
	digits[8] = '8';
	digits[9] = '9';
	digits[10] = 'a';
	digits[11] = 'b';
	digits[12] = 'c';
	digits[13] = 'd';
	digits[14] = 'e';
	digits[15] = 'f';
}

void	init_upper_digits(char *digits)
{
	digits[0] = '0';
	digits[1] = '1';
	digits[2] = '2';
	digits[3] = '3';
	digits[4] = '4';
	digits[5] = '5';
	digits[6] = '6';
	digits[7] = '7';
	digits[8] = '8';
	digits[9] = '9';
	digits[10] = 'A';
	digits[11] = 'B';
	digits[12] = 'C';
	digits[13] = 'D';
	digits[14] = 'E';
	digits[15] = 'F';
}
