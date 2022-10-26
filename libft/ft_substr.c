/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:08:34 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/08 17:07:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
Return value: The substring.
NULL if the allocation fails.
*/

static char	*input_check(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	rlen;
	size_t	l;

	str = input_check(s, start, len);
	if (!str)
		return (NULL);
	l = ft_strlen(s);
	if ((size_t)start > l - 1)
		len = 0;
	rlen = l - (size_t)start;
	if (rlen > len)
	{
		ft_memcpy(str, s + start, len);
		*(str + len) = '\0';
	}
	else
	{
		ft_memcpy(str, s + start, rlen);
		*(str + rlen) = '\0';
	}
	return (str);
}

static char	*input_check(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	rlen;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if ((size_t)start > l - 1)
		len = 0;
	rlen = l - (size_t)start;
	if (rlen > len)
		str = malloc (len + 1);
	else
		str = malloc (rlen + 1);
	if (!str)
		return (NULL);
	return (str);
}

// int	main(void)
// {
// 	const char	s[] = "01234567";
// 	printf("%s\n", ft_substr(s, 25, 40));
// 	return (0);
// }