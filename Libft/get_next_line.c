/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:01 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/29 19:16:24 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_clear_stack(char *stack)
{
	char	*new;
	int		len_line;
	int		j;
	size_t	len_stack;

	len_line = 0;
	while (stack[len_line] != '\n' && stack[len_line] != '\0')
		len_line++;
	if (!stack[len_line])
		return (free(stack), stack = NULL, NULL);
	len_stack = ft_gnl_strlen(stack);
	new = malloc (sizeof (char) * (len_stack - len_line + 1));
	if (!new)
		return (free(stack), stack = NULL, NULL);
	j = 0;
	len_line++;
	while (stack[len_line] != '\0')
	{
		new[j] = stack[len_line];
		j++;
		len_line++;
	}	
	new[j] = '\0';
	return (free(stack), stack = NULL, new);
}

char	*ft_read_from_buffer(int fd, char *stack)
{
	char	*buffer;
	int		ck_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stack), stack = NULL, NULL);
	ft_gnl_bzero(buffer, BUFFER_SIZE + 1);
	ck_read = 1;
	while (ck_read > 0 && !ft_gnl_strchr(buffer, '\n'))
	{
		ck_read = read (fd, buffer, BUFFER_SIZE);
		if (ck_read < 0)
		{
			return (free(buffer), free(stack), stack = NULL, NULL);
		}
		if (ck_read == 0)
			break ;
		buffer[ck_read] = '\0';
		stack = ft_gnl_strjoin(stack, buffer);
		if (!stack)
			return (free(stack), stack = NULL, free(buffer), NULL);
	}
	free(buffer);
	return (stack);
}

char	*ft_get_line(char *stack)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[0] == '\0')
		return (NULL);
	line = malloc (sizeof (char) *(i + 1 + (stack[i] == '\n')));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line [j] = stack[j];
		j++;
	}
	if (stack[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (stack != NULL)
		{
			free(stack);
			stack = NULL;
		}
		return (NULL);
	}
	stack = ft_read_from_buffer(fd, stack);
	if (!stack)
		return (free(stack), stack = NULL, NULL);
	line = ft_get_line(stack);
	if (!line)
		return (free(stack), stack = NULL, line);
	stack = ft_clear_stack(stack);
	if (!stack)
		return (free(stack), stack = NULL, line);
	return (line);
}
