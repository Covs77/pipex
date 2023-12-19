/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:07:18 by cleguina          #+#    #+#             */
/*   Updated: 2023/05/03 21:36:26 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	resto;

	if (nb == -2147483648)
	{
		ft_putchar_fd ('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		resto = (nb % 10);
		nb = (nb / 10);
		ft_putnbr_fd (nb, fd);
		ft_putchar_fd (resto + '0', fd);
	}
	else
		ft_putchar_fd (nb + '0', fd);
}
