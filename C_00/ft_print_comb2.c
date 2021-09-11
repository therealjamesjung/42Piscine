/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:17:19 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/11 16:17:21 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:43:11 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/11 15:43:13 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_data
{
	char c;
	int i;
	int j;
} t_data;

t_data _init(void)
{
	t_data res;

	res.c = '0';
	res.i = 0;
	res.j = 0;

	return res;
}

int	_get_digits(int n)
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
	if (digit < 10)
	{
		tmp = '0';
		write (1, &tmp, 1);
	}
	while (digit > 0)
	{
		tmp = '0' + (nb / digit);
		write (1, &tmp, 1);
		nb -= digit * (nb / digit);
		digit /= 10;
	}
}


void	_print_seperator(t_data data)
{
	char c;

	if (data.i == 98 && data.j == 99)
	{
		c = '\n';
		write (1, &c, 1);
	}
	else
	{
		c = ',';
		write(1, &c, 1);
		c = ' ';
		write(1, &c, 1);
	}
}

void	_print(t_data data)
{
	char c;

	c = ' ';
	ft_putnbr(data.i);
	write (1, &c, 1);
	ft_putnbr(data.j);
	_print_seperator(data);
}

void	ft_print_comb2(void)
{
	t_data d;
	
	d = _init();
	while (d.i < 100)
	{
		d.j = d.i + 1;
		while (d.j < 100)
		{
			_print(d);
			d.j++;
		}
		d.i++;
	}
}