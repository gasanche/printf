/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:53:14 by gabsanch          #+#    #+#             */
/*   Updated: 2023/06/02 11:11:11 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nb_is_zero(int nb, char *number)
{
	char	*nb_zero;

	free (number);
	nb_zero = (char *)ft_calloc(2, 1);
	if (nb_zero == NULL)
		return (NULL);
	nb_zero[0] = nb + '0';
	return (nb_zero);
}

static int	ft_digit_count(long int nb)
{
	long int	digits;

	digits = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		digits++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char		*number;
	long int	digits;
	long int	nb;

	nb = n;
	digits = ft_digit_count(nb);
	number = malloc((digits + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	number[digits--] = '\0';
	if (nb == 0)
		number = ft_nb_is_zero(nb, number);
	if (nb < 0)
	{
		number[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		number[digits--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (number);
}
