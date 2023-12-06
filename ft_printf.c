/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:07:46 by gabsanch          #+#    #+#             */
/*   Updated: 2023/07/23 19:59:03 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "library/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_type(va_list args, char const letter)
{
	int	print_len;

	print_len = 0;
	if (letter == 'c')
		print_len = ft_putchar(va_arg(args, int));
	else if (letter == 's')
		print_len = ft_string(va_arg(args, char *));
	else if (letter == 'p')
		print_len = ft_pointer(va_arg(args, unsigned long long));
	else if (letter == 'd')
		print_len = ft_number(va_arg(args, int));
	else if (letter == 'i')
		print_len = ft_number(va_arg(args, int));
	else if (letter == 'u')
		print_len = ft_unsigned(va_arg(args, unsigned int));
	else if (letter == 'x')
		print_len = ft_hexa(va_arg(args, unsigned int), letter);
	else if (letter == 'X')
		print_len = ft_hexa(va_arg(args, unsigned int), letter);
	else if (letter == '%')
		print_len = ft_putchar('%');
	return (print_len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;
	int		tmp_print_len;

	va_start(args, str);
	i = 0;
	print_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp_print_len = ft_type(args, str[i + 1]);
			i++;
		}
		else
			tmp_print_len = ft_putchar(str[i]);
		if (tmp_print_len == -1)
			return (-1);
		print_len = print_len + tmp_print_len;
		i++;
	}
	va_end(args);
	return (print_len);
}
/*
int	main(void)
{
	int	j = 123;
	int i = ft_printf("%d", j);

	printf("%i", i);
	return (0);
}*/
