/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:53:56 by gabsanch          #+#    #+#             */
/*   Updated: 2023/05/14 19:41:04 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = i;
			k = 0;
			while (haystack[j] == needle[k] && j < len && needle[k])
			{
				j++;
				k++;
			}
			if (needle[k] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	const char s1[] = "aaabcabcd";
	const char s2[] = "aabc";
	char *str = strnstr(s1, s2, -1);

	printf("%s\n", ft_strnstr(s1, s2, -1));
	printf("%s", str);
}*/
