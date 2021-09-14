/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:23:58 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/14 22:22:17 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	_get_digits(int n)
{
	int	digit;

	digit = 1;
	while (n >= 10)
	{
		digit *= 10;
		n /= 10;
	}
	return (digit);
}

void	ft_putnbr(int nb)
{
	char	c;
	char	tmp;
	int		digit;

	c = '0';
	if (nb < 0)
	{
		tmp = '-';
		write (1, &tmp, 1);
		nb *= -1;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	digit = _get_digits(nb);
	while (digit > 0)
	{
		tmp = '0' + (nb / digit);
		write (1, &tmp, 1);
		nb -= digit * (nb / digit);
		digit /= 10;
	}
}
