/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:52:36 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:11:48 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_check_nmb(int nb)
{
	if (nb == -2147483648)
		return (2);
	else if (nb < 0)
		return (1);
	return (0);
}

char	*ft_print_itoa(int n)
{
	char	*res;
	int		i;
	int		digit;

	i = ft_check_nmb (n);
	if (i == 2)
		n = 147483648;
	if (i == 1)
		n = -n;
	digit = ft_print_countdigit(n) + i;
	res = (char *) malloc((sizeof (char) * digit) + 1);
	if (!res)
		return (0);
	if ((i == 1) || (i == 2))
		res[0] = '-';
	if (i == 2)
		res[1] = '2';
	res[digit] = 0;
	while ((n >= 0) && (i <= digit - 1))
	{
		res[digit - 1] = (n % 10) + '0';
		n = n / 10;
		digit--;
	}
	return (res);
}
