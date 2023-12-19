/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:55:44 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/21 19:00:59 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l_s1;
	size_t	l_s2;
	size_t	l_s3;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	l_s3 = l_s1 + l_s2;
	if (!s1 && !s2)
		return (0);
	s3 = malloc (sizeof(char) * l_s3 + 1);
	if (s3 == NULL)
		return (0);
	s3 = ft_memcpy(s3, s1, l_s1);
	s3 = s3 + l_s1;
	s3 = ft_memcpy(s3, s2, l_s2 + 1);
	return (s3 - (l_s1));
}
