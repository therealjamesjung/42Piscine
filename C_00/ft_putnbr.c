/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:23:58 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/11 16:24:40 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int _get_digits(int n)
{
	int digit;

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
	char 	tmp;
	int		digit;

	c = '0';
	if (nb < 0)
	{
		tmp = '-';
		write (1, &tmp, 1);
		nb *= -1;
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
