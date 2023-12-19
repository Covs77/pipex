/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:26:48 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/09 15:11:08 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_free(char *s1, char *s2)
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
	free(s1);
	return (s3 - (l_s1));
}
