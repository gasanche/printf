/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:14:54 by gabsanch          #+#    #+#             */
/*   Updated: 2023/07/16 18:26:36 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_string(char *str);
int		ft_number(int num);
char	*ft_itoa(int n);
int		ft_hexa(unsigned int num, char const type);
int		ft_hexa_len(unsigned int num);
int		ft_putchar(char c);
int		ft_printf(char const *str, ...);
int		ft_pointer(unsigned long long int pt);
char	*ft_utoa(unsigned int num);
int		ft_utoa_size(unsigned int num);
int		ft_unsigned(unsigned int num);
int		ft_hexa_pt(unsigned long long p);
int		ft_p_len(unsigned long long p);
#endif
