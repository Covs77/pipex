/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:25:41 by cova              #+#    #+#             */
/*   Updated: 2024/01/16 19:51:37 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../Libft/libft.h"

void	ft_error(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_l(void)
{
	system("leaks -q pipex");
}

char	*ft_find_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**path_split;

	i = 0;
	while (ft_strnstr (envp[i], "PATH", 4) == 0)
		i++;
	path_split = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_split[i])
	{
		path = ft_strjoin(path_split[i], "/");
		path = ft_strjoin(path, cmd);
		free(path_split[i]);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	exit(127);
}

int ft_open_file (char *argv, int i)
{
	int file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error("Error: File not found\n", 2);
	return (file);
}

int	ft_get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}