/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:07:03 by cleguina          #+#    #+#             */
/*   Updated: 2023/05/01 21:28:28 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

int	ft_getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = len;
	while (0 < i)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ini;
	size_t	end;
	size_t	i;
	size_t	j;
	char	*str_new;

	ini = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	i = ini;
	j = 0;
	if (!s1 || (end == 0))
		return (ft_strdup(""));
	if (ini <= end)
		str_new = (char *) malloc (sizeof(char) * (end - ini) + 2);
	else
		return (0);
	if (!str_new)
		return (0);
	while (j <= (end - ini))
	{
		str_new[j] = s1[i++];
		j++;
	}
	str_new[j] = '\0';
	return (str_new);
}
