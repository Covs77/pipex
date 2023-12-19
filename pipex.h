/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:25:35 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/19 18:28:45 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>


typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	*infile;
	char	*outfile;
}				t_pipex;

int main (int argc, char **argv, char **envp);
void	ft_l(void);
#endif