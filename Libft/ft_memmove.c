/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:07:41 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/26 18:43:57 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  DESCRIPTION
     The memmove() function copies len bytes from string src to string dst. 
	 The two strings may overlap; the copy is always done
     in a non-destructive manner.

	RETURN VALUES
     The memmove() function returns the original value of dst.*/

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*orig;
	char	*dest;
	size_t	pos;

	orig = (char *)src;
	dest = (char *)dst;
	pos = 0;
	if (dest == NULL && orig == NULL)
		return (dst);
	if (dest > orig)
		while (len-- > 0)
			dest [len] = orig [len];
	else
	{
		while (pos < len)
		{
			dest[pos] = orig[pos];
			pos++;
		}
	}
	return (dst);
}
