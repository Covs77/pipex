/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:25:41 by cova              #+#    #+#             */
/*   Updated: 2024/01/15 18:35:21 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
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
