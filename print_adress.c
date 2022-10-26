/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:51:54 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/24 10:19:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_x(unsigned long nb, int count, char *radix);
static int	set_conv(unsigned long n, int conv, char *radix);
static int	print_hex_lj(unsigned long n, int count, int conv, t_flags *flags);
static int	print_hex_rj(unsigned long n, int count, int conv, t_flags *flags);

int	print_adress(unsigned long ptr, int count, t_flags *flags)
{
	int	conv;

	conv = 3;
	if (!ptr)
	{
		count = print_spaces_p(count, conv, flags);
		count = print_error_p(count);
		return (count);
	}
	conv = 0;
	conv = set_conv(ptr, conv, "0123456789abcdef");
	if (flags->minus == 1)
		count = print_hex_lj(ptr, count, conv, flags);
	else
		count = print_hex_rj(ptr, count, conv, flags);
	return (count);
}

static int	print_hex_lj(unsigned long n, int count, int conv, t_flags *flags)
{
	count = print_hash(count);
	count = ft_putnbr_x((unsigned long) n, count, "0123456789abcdef");
	count = print_spaces_p(count, conv, flags);
	return (count);
}

static int	print_hex_rj(unsigned long n, int count, int conv, t_flags *flags)
{
	count = print_spaces_p(count, conv, flags);
	count = print_hash(count);
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

static int	set_conv(unsigned long n, int conv, char *radix)
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
