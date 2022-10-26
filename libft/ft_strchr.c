/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:15:59 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/07 10:42:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The	strchr(void)  function  returns  a  pointer  to the first occurrence of the 
character c in the string s.
Here "character" means "byte"; these functions do not work with wide or 
multibyte characters.
The	strchr(void) and strrchr() functions return a pointer to the matched 
character or NULL if the character is not found. The terminating null byte is 
considered part of the string, so that if c is specified as '\0', these 
functions return a pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((void *)&s[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char	*s;
// 	char	c;

// 	s = "Sambadijaneiro";
// 	c = 'i';
// 	printf("%s\n", strchr(s, c));
// 	printf("%s\n", ft_strchr(s, c));
// 	return (0);
// }
