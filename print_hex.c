/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:12:47 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/24 17:20:34 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_x(unsigned long nb, int count, char *radix);
static int	set_conv(unsigned int n, int conv, char *radix);
static int	print_hex_lj(unsigned int n, int count, int conv, t_flags *flags);
static int	print_hex_rj(unsigned int n, int count, int conv, t_flags *flags);

int	print_hex(unsigned int n, int count, t_flags *flags)
{
	int	conv;

	conv = 0;
	if (n == 0 && flags->precision == 0 && flags->dot == 1)
	{
		count = print_spaces_x(count, 0, flags);
		return (count);
	}
	conv = set_conv(n, conv, "0123456789abcdef");
	if (flags->minus == 1)
		count = print_hex_lj(n, count, conv, flags);
	else
		count = print_hex_rj(n, count, conv, flags);
	return (count);
}

static int	print_hex_lj(unsigned int n, int count, int conv, t_flags *flags)
{
	if (flags->hash == 1 && n != 0)
		count = print_hash(count);
	if (flags->zero == 1 || flags->dot == 1)
		count = print_zeroes_u(count, conv, flags);
	count = ft_putnbr_x((unsigned long) n, count, "0123456789abcdef");
	if (flags->zero == 0 || (flags->zero == 1 && flags->dot == 1))
		count = print_spaces_x(count, conv, flags);
	return (count);
}

static int	print_hex_rj(unsigned int n, int count, int conv, t_flags *flags)
{
	if (flags->zero == 0 || (flags->zero == 1 && flags->dot == 1))
		count = print_spaces_x(count, conv, flags);
	if (flags->hash == 1 && n != 0)
		count = print_hash(count);
	if (flags->zero == 1 || flags->dot == 1)
		count = print_zeroes_u(count, conv, flags);
	count = ft_putnbr_x((unsigned long) n, count, "0123456789abcdef");
	return (count);
}

static int	ft_putnbr_x(unsigned long nb, int count, char *radix)
{
	if (nb >= 16)
	{
		count = ft_putnbr_x(nb / 16, count, radix);
		count = ft_putnbr_x(nb % 16, count, radix);
	}
	else
	{
		ft_putchar_fd(radix[nb], 1);
		count ++;
	}
	return (count);
}

static int	set_conv(unsigned int n, int conv, char *radix)
{
	if (n >= 16)
	{
		conv = set_conv(n / 16, conv, radix);
		conv = set_conv(n % 16, conv, radix);
	}
	else
		conv++;
	return (conv);
}
