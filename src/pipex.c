/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:52 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 20:53:43 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/libft.h"


void	ft_l(void)
{
	system("leaks -q pipex");
}
void ft_error(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}


void ft_init_struct(t_pipex *pipex)
{
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->infile = 0;
	pipex->outfile = 0;
}

void ft_read_files (t_pipex *pipex, char **argv, int argc)
{
	pipex->file1 = open(argv[1], O_RDONLY);
	if (pipex->file1 == -1)
	{
		ft_error("Error: File can't be opened", 2);
		exit(EXIT_FAILURE);
	}
	pipex->file2 = open(argv[argc- 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->file2 == -1)
	{
		ft_error("Error: File can't be opened", 2);
		exit(EXIT_FAILURE);
	}	
}


/// tendría que ver la manera de hacerlo sin estructura

int main(int argc, char **argv)
{
	t_pipex	*pipex;
	
	if (argc != 5)
		return (ft_error("Error: Wrong number of args\n", 2), EXIT_FAILURE);
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	ft_init_struct(pipex);
	ft_read_files(pipex, argv, (argc));
	atexit(ft_l);
	return(0);
}