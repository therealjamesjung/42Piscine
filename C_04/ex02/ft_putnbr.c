/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:44:22 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/20 20:44:23 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	char	tmp;
	int		digit;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
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
