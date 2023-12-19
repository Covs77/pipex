/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:47:37 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/20 16:26:19 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

long int	ft_atoi(const char *str)
{
	long int	num;
	long int	sign;

	sign = 1;
	num = 0;
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str++;
	}
	if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (sign * num);
}
