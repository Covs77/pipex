/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:50:06 by cleguina          #+#    #+#             */
/*   Updated: 2024/01/11 14:25:41 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

void	ft_parent_process_b(char **argv, char **envp, int *fd);
void	ft_child_process_b(char **argv, char **envp, int *fd);
void	ft_exe(char *argv, char **envp);
void	ft_error(char *str, int fd);
char	*ft_find_path(char *cmd, char **envp);
void	ft_l(void);

#endif