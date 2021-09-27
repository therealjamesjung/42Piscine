/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:17:09 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/27 14:23:23 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index++], 1);
	}
}

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

void	ft_show_tab(t_stock_str *p)
{
	int	index;

	index = 0;
	while (p[index].str != 0)
	{
		ft_putstr(p[index].str);
		ft_putstr("\n");
		ft_putnbr(p[index].size);
		ft_putstr("\n");
		ft_putstr(p[index].copy);
		ft_putstr("\n");
		index++;
	}
}
