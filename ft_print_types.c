/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:38:46 by gabsanch          #+#    #+#             */
/*   Updated: 2023/07/16 18:26:54 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "library/libft.h"

int	ft_string(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len] != '\0')
	{
		if (ft_putchar(str[len]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_number(int num)
{
	int		len;
	char	*str_num;

	len = 0;
	str_num = ft_itoa(num);
	if (str_num == NULL)
		return (-1);
	len = ft_string(str_num);
	free(str_num);
	return (len);
}

int	ft_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

int	ft_hexa(unsigned int num, char const type)
{
	int	writted;

	writted = 0;
	if (num >= 16)
	{
		if (ft_hexa(num / 16, type) == -1)
			return (-1);
		if (ft_hexa(num % 16, type) == -1)
			return (-1);
	}
	else
	{
		if (num <= 9)
			writted = ft_putchar(num + '0');
		else
		{
			if (type == 'x')
				writted = ft_putchar(num - 10 + 'a');
			else if (type == 'X')
				writted = ft_putchar(num - 10 + 'A');
		}
		if (writted == -1)
			return (-1);
	}
	return (ft_hexa_len(num));
}

int	ft_unsigned(unsigned int num)
{
	int		len;
	char	*str_num;

	len = 0;
	str_num = ft_utoa(num);
	if (str_num == NULL)
		return (-1);
	len = ft_string(str_num);
	free(str_num);
	return (len);
}
