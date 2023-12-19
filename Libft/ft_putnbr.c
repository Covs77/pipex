/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:56:28 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/14 18:10:06 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	resto;

	if (nb == -2147483648)
	{
		ft_putchar ('-');
		ft_putchar('2');
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		resto = (nb % 10);
		nb = (nb / 10);
		ft_putnbr (nb);
		ft_putchar(resto + '0');
	}
	else
		ft_putchar (nb + '0');
}

/* int	main(void)
{
	ft_putnbr(648);
	return (0);
}
 */