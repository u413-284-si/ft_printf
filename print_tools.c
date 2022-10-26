/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:51:01 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/24 18:18:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spaces(int nb, int count, int conv, t_flags *flags)
{
	int	n;
	int	neg;

	neg = 0;
	if (nb < 0 && flags->sign == 0)
		neg = 1;
	if (flags->dot == 1)
		n = flags->width - flags->sign - neg - flags->space
			- conv;
	else
		n = flags->width - flags->sign - neg - conv;
	while (n-- > 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	print_spaces_u(int count, int conv, t_flags *flags)
{
	int	n;

	if (flags->dot == 1 && flags->precision > conv)
		n = flags->width - flags->precision;
	else
		n = flags->width - conv;
	while (n-- > 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	print_zeroes(int nb, int count, int conv, t_flags *flags)
{
	int	n;
	int	neg;

	neg = 0;
	if (nb < 0 && flags->sign == 0 && flags->dot == 0)
		neg = 1;
	if (flags->dot == 1)
		n = flags->precision - neg - conv;
	else
		n = flags->width - flags->sign - neg - flags->space - conv;
	while (n-- > 0)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	return (count);
}

int	print_zeroes_u(int count, int conv, t_flags *flags)
{
	int	n;

	if (flags->dot == 1)
		n = flags->precision - conv;
	else
		n = flags->width - conv;
	while (n-- > 0)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	return (count);
}

int	print_sign(int count, int sign)
{
	if (sign == 1)
		ft_putchar_fd('+', 1);
	else
		ft_putchar_fd('-', 1);
	count++;
	return (count);
}
