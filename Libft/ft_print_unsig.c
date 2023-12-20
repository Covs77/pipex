/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:29:28 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:12:12 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_print_unsig(unsigned int num)
{
	char		*num_conv;
	long long	num2;
	int			printed;

	num2 = 4294967896 + num;
	if (num > 0)
		num2 = num;
	num_conv = ft_print_utoa(num2);
	ft_print_str(num_conv);
	printed = ft_print_strlen (num_conv);
	free(num_conv);
	return (printed);
}
