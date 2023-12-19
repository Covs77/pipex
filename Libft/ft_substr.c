/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:39:18 by cleguina          #+#    #+#             */
/*   Updated: 2023/05/01 18:54:50 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reserva memeria (malloc) y devuelve una substring de la string ’s’.
Substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’. */

#include "libft.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc (sizeof(char) * len + 1);
	if (substr == NULL)
		return (0);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
