/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:29:45 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/26 18:43:43 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	pos;

	pos = 0;
	if (!dst && !src)
		return (0);
	while (pos < n)
	{
		((unsigned char *)dst)[pos] = ((unsigned char *)src)[pos];
		pos++;
	}
	return (dst);
}
