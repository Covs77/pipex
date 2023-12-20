/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:51:31 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:11:55 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long x)
{
	char	*hexa_str;
	char	res[100];
	int		i;
	int		printed;

	i = 0;
	printed = 0;
		hexa_str = "0123456789abcdef";
	while (x >= 16)
	{
		res[i] = hexa_str[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa_str[x];
	while (i >= 0)
	{
		ft_print_char(res[i]);
		i--;
		printed++;
	}
	return (printed);
}
