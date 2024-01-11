/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:49:18 by cleguina          #+#    #+#             */
/*   Updated: 2024/01/11 16:53:41 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../includes/pipex.h"
#include "../Libft/libft.h"

void	ft_child_process_b(int i, char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error("Error: File 1 failed\n", 2);
	dup2 (fd[1], STDOUT_FILENO);
	dup2 (filein, STDIN_FILENO);
	close(fd[0]);
	ft_exe(argv[i], envp);
}


void	ft_parent_process_b(int argc, char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		ft_error("Error: File 1 failed\n", 2);
	dup2 (fd[0], STDIN_FILENO);
	dup2 (fileout, STDOUT_FILENO);
	close(fd[1]);
	ft_exe(argv[argc - 1], envp);
}

int ft_heredoc (char **argv)
{
	int file;
	//abro y guardo el contenido del here_doc
	
	file = open(argv[1], O_RDONLY, O_WRONLY, O_TRUNC, 0777);
	if (file == -1)
		ft_error("Error. Here_doc failed\n", 2);
	while (1)
	{
		

	}	
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		i;
	pid_t	pid;
	int 	here_doc;
	

	if (argc < 5)
		ft_error("Error: Wrong number of args\n", 2);
	i = 2;
	if (ft_strncmp (argv[1], "here_doc", strlen("heredoc") == 0))
	{
		here_doc = ft_heredoc(argv);
	}
	while (i != argc - 2)
	{
		if (pipe(fd) == -1)
			ft_error("Error: Pipe failed\n", 2);
		pid = fork();
		if (pid == -1)
			ft_error("Error: Fork failed\n", 2);
		if (pid == 0)
			ft_child_process_b(i , argv, envp, fd);
		waitpid(pid, NULL, 0);
		i++;
	}	
	ft_parent_process_b(i, argv, envp, fd);
	return (0);
}