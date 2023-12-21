/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:25:35 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/21 19:21:21 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void	ft_parent_process (char **argv, char **envp, int *fd);
void	ft_child_process (char **argv, char **envp, int *fd);
void	ft_exe(char *argv, char **envp);
void	ft_error(char *str, int fd);
char	*ft_find_path(char *cmd, char **envp);
void	ft_l(void);

#endif