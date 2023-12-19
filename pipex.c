/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:52 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/19 19:41:41 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_l(void)
{
	system("leaks -q pipex");
}

int main (int argc, char **argv)
{
	argv = NULL;
	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	
	atexit(ft_l);
}