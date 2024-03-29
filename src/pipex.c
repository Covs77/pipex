/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:52 by cleguina          #+#    #+#             */
/*   Updated: 2024/01/18 18:31:21 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/libft.h"

// int execve(const char *pathname, char *const argv[], char *const envp[]);

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
		ft_error("Error: Command not found\n", 2);
	}
}

//preparo el proceso hijo para ser ejecutado.
//abro el archivo 1: argv[1]=fd[0], en solo lectura con todos los permisos.

void	ft_child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error("Error: File 1 failed\n", 2);
	dup2 (fd[1], STDOUT_FILENO);
	dup2 (filein, STDIN_FILENO);
	close(fd[0]);
	ft_exe(argv[2], envp);
}

//preparo el proceso padre para ser ejecutado.
//abro el archivo 1: argv[1]=fd[0], en solo lectura con todos los permisos.

void	ft_parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		ft_error("Error: File 1 failed\n", 2);
	dup2 (fd[0], STDIN_FILENO);
	dup2 (fileout, STDOUT_FILENO);
	close(fd[1]);
	ft_exe(argv[3], envp);
}

//Argumentos: 
//file1	  cmd1	  cmd2 	  file2
//argv[1] argv[2] argv[4] argv[5]

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_error("Error: Wrong number of args\n", 2);
	if (pipe(fd) == -1)
		ft_error("Error: Pipe failed\n", 2);
	pid = fork();
	if (pid == -1)
		ft_error("Error: Fork failed\n", 2);
	if (pid == 0)
		ft_child_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	ft_parent_process(argv, envp, fd);
	exit(EXIT_SUCCESS);
	return (0);
}
