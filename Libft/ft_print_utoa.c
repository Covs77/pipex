/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:26:33 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:12:15 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_utoa(long long n)
{
	char	*res;
	int		i;
	int		digit;

	i = 0;
	digit = ft_print_countdigit(n) + i;
	res = (char *) malloc((sizeof (char) * digit) + 1);
	if (!res)
		return (0);
	res[digit] = 0;
	while ((n >= 0) && (i <= digit - 1))
	{
		res[digit - 1] = (n % 10) + '0';
		n = n / 10;
		digit--;
	}
	return (res);
}
