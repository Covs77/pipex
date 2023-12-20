/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:52 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/20 19:01:09 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/libft.h"


void	ft_l(void)
{
	system("leaks -q pipex");
}

int main (int argc, char **argv)
{
	argv[1] = NULL;
	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	
	atexit(ft_l);
}