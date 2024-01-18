/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:49:18 by cleguina          #+#    #+#             */
/*   Updated: 2024/01/18 18:58:52 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../includes/pipex.h"
#include "../Libft/libft.h"

void	ft_exe(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = ft_find_path(cmd[0], envp);
	if (path == 0)
	{
		ft_free_matrix(cmd);
		ft_error("Error: Command not found\n", 2);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free_matrix(cmd);
		ft_error("Error: Path not found\n", 2);
	}
}

void	ft_child_process_b(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Pipe failed\n", 2);
	pid = fork();
	if (pid == -1)
		ft_error("Fork failed\n", 2);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exe(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_heredoc(char *limit, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_error ("Error: Wrong number of arguments\n", 2);
	if (pipe(fd) == -1)
		ft_error("Error: Pipe failed\n", 2);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (ft_get_next_line(&line))
		{
			if (ft_strncmp(line, limit, ft_strlen(limit)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fileout;
	int		filein;

	if (argc >= 4)
	{
		if (ft_strncmp (argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = ft_open_file(argv[argc - 1], 0);
			write(2, "heredoc >\n", 10);
			ft_heredoc (argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = ft_open_file(argv[argc - 1], 1);
			filein = ft_open_file(argv[1], 2);
			dup2 (filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			ft_child_process_b(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		ft_exe(argv[i], envp);
	}
	ft_error("Error: Wrong number of arguments\n", 2);
}
