/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:52 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/19 18:01:02 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_l(void)
{
	system("leaks -q so_long");
}

int main (int argc, char **argv, char **envp)
{
	atexit(ft_l);
}