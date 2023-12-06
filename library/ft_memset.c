/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:50:53 by gabsanch          #+#    #+#             */
/*   Updated: 2023/05/11 15:57:00 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*s;
	size_t	i;

	s = (char *)str;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (str);
}
