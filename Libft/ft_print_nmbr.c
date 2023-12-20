/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nmbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:27:48 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:11:52 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nmbr(int num)
{
	char	*num_conv;
	int		printed;

	num_conv = ft_print_itoa(num);
	printed = ft_print_strlen(num_conv);
	ft_print_str(num_conv);
	free(num_conv);
	return (printed);
}
