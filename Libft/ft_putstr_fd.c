/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:24:58 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/29 21:10:47 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		cont;
	char	c;

	cont = 0;
	c = s[cont];
	while (c != '\0')
	{
		write(fd, &c, 1);
		cont++;
		c = s[cont];
	}
}
