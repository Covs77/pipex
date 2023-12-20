/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:21:30 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:12:04 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_print_str(char *str)
{
	int		cont;
	char	c;

	if (!str)
		return (ft_print_str("(null)"));
	cont = 0;
	c = str[cont];
	while (c != '\0')
	{
		write(1, &c, 1);
		cont++;
		c = str[cont];
	}
	return (cont);
}
