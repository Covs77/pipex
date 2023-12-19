/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:04:32 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/22 16:15:13 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || \
			(s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			words++;
		i++;
	}
	return (words);
}

char	**ft_freeall(char **list)
{
	size_t	j;

	j = 0;
	if (list)
	{
		while (list[j])
		{
			free(list[j]);
			j++;
		}
		free(list);
	}
	return (NULL);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (n == 0)
		return (NULL);
	str = malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	ini_w;
	size_t	k;

	i = 0;
	k = 0;
	res = malloc (sizeof(char *) * (ft_words(s, c) + 1));
	if (!res)
		return (0);
	while (i < ft_words(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		ini_w = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		res[i] = ft_strndup(&s[ini_w], k - ini_w);
		if (res [i++] == 0)
			return (ft_freeall(res));
	}
	res[i] = NULL;
	return (res);
}
