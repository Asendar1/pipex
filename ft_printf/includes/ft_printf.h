/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:59:15 by hassende          #+#    #+#             */
/*   Updated: 2024/09/12 11:59:20 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void		check_specifier(const char *format, va_list args, int *prt_len);
void		check_hex(const char *format, va_list args, int *prt_len);
int			ft_putchar(char c);
void		ft_puthexa(unsigned long long int n, int *prt_len);
void		ft_prthexa(unsigned int n, int uppercase, int *prt_len);
int			ft_putstr(char *str);
void		ft_putnbr(int n, int *prt_len);
void		ft_unsigned(unsigned int n, int *prt_len);
int			ft_printf(const char *format, ...);

#endif
