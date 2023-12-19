/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:33:13 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/29 20:06:03 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t		len;
	size_t		copy;
	char		*ptr;

	copy = 0;
	len = ft_strlen (s1);
	if (!s1)
		return ((void *)0);
	else
	{
		ptr = (char *) malloc (sizeof(char) *(len + 1));
		if (ptr == NULL)
			return (NULL);
		while (copy < len)
		{
			ptr[copy] = s1[copy];
			copy++;
		}
	}
	ptr[copy] = '\0';
	return ((char *) ptr);
}
