/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:49:18 by cleguina          #+#    #+#             */
/*   Updated: 2024/01/15 18:46:06 by cleguina         ###   ########.fr       */
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

//abro y guardo el contenido del here_doc.tmp

int	ft_heredoc(char **argv)
{
	int		file;
	int		std_in;
	char	*line;

	std_in = dup(STDIN_FILENO);
	file = open("here_doc.tmp", O_WRONLY, O_CREAT, O_TRUNC, 0644);
	if (file < 0)
		ft_error("Error. Here_doc failed\n", 2);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(std_in);
		if (!line)
			ft_error("Error. Read line failed\n", 2);
		if (!ft_strncmp(argv[2], line, ft_strlen(argv[2])))
		{
			close(std_in);
			break ;
		}
		write(file, line, ft_strlen(line));
		free (line);
	}
}

void	check_here_doc(char **argv, int *here_doc)
{
	if (ft_strncmp (argv[1], "here_doc", strlen("heredoc") == 0))
	{
		here_doc[1] = ft_heredoc(argv);
		here_doc[0] = 1;
	}
	else
	{
		here_doc[1] = open (argv[1], O_RDONLY, 0777);
		if (here_doc == -1)
			ft_error("Error: Open file failed\n", 2);
		here_doc[0] = 0;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		i;
	pid_t	pid;
	int		here_doc[2];

	if (argc < 5)
		ft_error("Error: Wrong number of args\n", 2);
	i = 2;
	check_here_doc(argv, here_doc);
	if (here_doc[0] == 1)
		i++;
	while (i != argc - 2)
	{
		if (pipe(fd) == -1)
			ft_error("Error: Pipe failed\n", 2);
		pid = fork();
		if (pid == -1)
			ft_error("Error: Fork failed\n", 2);
		if (pid == 0)
			ft_child_process_b(i, argv, envp, fd);
		waitpid(pid, NULL, 0);
		i++;
	}
	ft_parent_process_b(i, argv, envp, fd);
	return (0);
}
