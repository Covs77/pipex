/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:02:05 by cleguina          #+#    #+#             */
/*   Updated: 2023/04/23 22:02:05 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Localiza la primera ocurrencia de la cadena acabada en null de s2 en s1,
buscará no más de len caracteres. Los caracateres q aparezcan despues de `\0' 
no serán buscados.
RETURN VALUES
Si s2 está vacía, devuelve s1,si s2 no está en s1 devuelve NULL, sino
devuelve el puntero s2 en la primera ocurrencia encontrada.
*/

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char		*pos;
	size_t		i;
	size_t		j;
	size_t		lenght;

	i = -1;
	pos = NULL;
	lenght = ft_strlen(s2);
	if (!lenght)
		pos = (char *)s1;
	else
	{
		while (s1[++i] && i < len)
		{
			j = 0;
			while (s2[j] && s1[i + j] == s2[j] && i + j < len)
				j++;
			if (j == lenght)
			{
				pos = (char *)(s1 + i);
				break ;
			}
		}
	}
	return (pos);
}
