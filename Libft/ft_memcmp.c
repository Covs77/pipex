/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:20:59 by cleguina          #+#    #+#             */
/*   Updated: 2023/04/23 21:20:59 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* DESCRIPCIÓN
Compara s1 y s2 byte a byte. Se supone que ambas tienen n bytes de longitud.
RETURN VALUES
Devuelve 0 si s1 y s2 son idénticas, sino devulve la diferencia entre los  
dos primerros bytes diferentes (leidos como unsignes char) 
Dos cadenas vacias son siempre idénticas. */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
