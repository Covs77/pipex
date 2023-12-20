/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:30:27 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:11:42 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int x, char cap)
{
	char	*hexa_str;
	char	res[100];
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	if (cap == 'x' || cap == 'p')
		hexa_str = "0123456789abcdef";
	else
		hexa_str = "0123456789ABCDEF";
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
