/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:55:30 by cleguina          #+#    #+#             */
/*   Updated: 2023/04/27 19:41:44 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Localiza la última aparcición de c en la cadena s.

#include <unistd.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;
	char	cc;

	cc = (char)c;
	len = ft_strlen (s);
	str = (char *)s;
	while (len > 0)
	{
		if (str[len] == cc)
			return (&str[len]);
		len--;
	}
	if (str[len] == cc)
		return (&str[len]);
	return (NULL);
}
