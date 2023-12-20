/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:57:45 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:11:59 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_print_putstr(char *str)
{
	int		cont;
	char	c;

	cont = 0;
	c = str[cont];
	while (c != '\0')
	{
		write(1, &c, 1);
		cont++;
		c = str[cont];
	}
	return (1);
}
