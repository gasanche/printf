/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:49:43 by gabsanch          #+#    #+#             */
/*   Updated: 2023/06/08 13:40:20 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str++;
	}
	if (*str == (char)c)
	{
		return (str);
	}
	return (0);
}
/*
#include <string.h>
int main()
{
   char s[11] = "teste";
   int c = 'e' + 256;
 
   printf( "s=%s\t", s );
   printf( "c=%c\n", c );
   printf( "strchr=\"%s\"\n", strchr( "teste", 'e' + 256 ) );
   printf( "ft_strchr=\"%s\"", ft_strchr("teste", 'e' + 256));
   printf( "strchr=\"%s\"\n", strchr( "teste", 1024 ) );
   printf( "ft_strchr=\"%s\"", ft_strchr("teste", 1024));
 
   return 0;
}*/
