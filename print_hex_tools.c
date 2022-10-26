/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:10 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/24 17:46:16 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hash(int count)
{
	ft_putstr_fd("0x", 1);
	count += 2;
	return (count);
}

int	print_hash_up(int count)
{
	ft_putstr_fd("0X", 1);
	count += 2;
	return (count);
}

int	print_spaces_x(int count, int conv, t_flags *flags)
{
	int	n;

	if (flags->hash == 1)
		flags->width -= 2;
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

int	print_spaces_p(int count, int conv, t_flags *flags)
{
	int	n;

	flags->width -= 2;
	if (flags->dot == 1)
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

int	print_error_p(int count)
{
	ft_putstr_fd("(nil)", 1);
	count += 5;
	return (count);
}
