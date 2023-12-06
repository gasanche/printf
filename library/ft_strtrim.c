/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:19:17 by gabsanch          #+#    #+#             */
/*   Updated: 2023/06/02 11:13:42 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		str_len;
	char	*str;

	start = 0;
	i = 0;
	str_len = ft_strlen(s1);
	while (ft_strchr(set, s1[i++]) != 0 && str_len != 0)
	{
		start++;
		str_len--;
	}
	if (str_len == 0)
		return (ft_calloc(1, 1));
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[--i]) != 0)
		str_len--;
	str = malloc(str_len + 1 * sizeof(char));
	if (str == 0)
		return (0);
	ft_memcpy(str, &s1[start], str_len);
	str[str_len] = '\0';
	return (str);
}
