/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:50:06 by cleguina          #+#    #+#             */
/*   Updated: 2024/01/16 19:56:50 by cleguina         ###   ########.fr       */
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

void	ft_heredoc(char *limit, int argc);
//void	ft_parent_process_b(int argc, char **argv, char **envp, int *fd);
void	ft_child_process_b(char *argv, char **envp);
void	ft_exe(char *argv, char **envp);
void	ft_error(char *str, int fd);
void	ft_l(void);
char	*ft_find_path(char *cmd, char **envp);
int		ft_open_file(char *argv, int i);
int		ft_get_next_line(char **line);

#endif