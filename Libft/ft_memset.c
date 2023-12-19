/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:42:22 by cleguina          #+#    #+#             */
/*   Updated: 2023/04/26 20:06:38 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			pos;

	pos = 0;
	s = str;
	while (pos < n)
	{
		s[pos] = (unsigned char) c;
		pos++;
	}
	return (str);
}
