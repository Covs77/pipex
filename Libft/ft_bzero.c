/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:39:39 by cleguina          #+#    #+#             */
/*   Updated: 2023/04/26 20:14:37 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;
	size_t			pos;

	pos = 0;
	s1 = (unsigned char *)s;
	while (pos < n)
	{
		s1[pos] = '\0';
		pos++;
	}
}
