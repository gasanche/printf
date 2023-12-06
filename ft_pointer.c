/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:30:08 by gabsanch          #+#    #+#             */
/*   Updated: 2023/07/15 19:05:49 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/libft.h"
#include "ft_printf.h"

int	ft_p_len(unsigned long long p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		len++;
		p = p / 16;
	}
	return (len);
}

int	ft_hexa_pt(unsigned long long num)
{
	if (num >= 16)
	{
		ft_hexa_pt(num / 16);
		ft_hexa_pt(num % 16);
	}
	else
	{
		if (num <= 9)
			return (ft_putchar(num + '0'));
		else
			return (ft_putchar(num - 10 + 'a'));
	}
	return (1);
}

int	ft_pointer(unsigned long long pt)
{
	int	len;
	int	writted;

	len = 0;
	writted = 0;
	writted = write(1, "0x", 2);
	if (writted == -1)
		return (-1);
	len += writted;
	if (pt == 0)
	{
		writted = write(1, "0", 1);
		if (writted == -1)
			return (-1);
		len += writted;
	}
	else
	{
		if (ft_hexa_pt(pt) == -1)
			return (-1);
		len += ft_p_len(pt);
	}
	return (len);
}
