/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:55:10 by cleguina          #+#    #+#             */
/*   Updated: 2023/04/28 19:15:29 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (n > i)
	{
		if (*str == chr)
			return ((void *) str);
		str++;
		n--;
	}
	return (NULL);
}
