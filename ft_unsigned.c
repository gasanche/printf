/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:30:21 by gabsanch          #+#    #+#             */
/*   Updated: 2023/07/16 18:28:35 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/libft.h"
#include "ft_printf.h"

int	ft_utoa_size(unsigned int num)
{
	if (num < 10)
		return (1);
	else
		return (1 + ft_utoa_size(num / 10));
}

char	*ft_utoa(unsigned int num)
{
	char	*number;
	int		i;
	int		len;

	len = ft_utoa_size(num);
	number = malloc((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len] = '\0';
	if (num == 0)
		number[0] = '0';
	i = len - 1;
	while (i >= 0)
	{
		number[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (number);
}
