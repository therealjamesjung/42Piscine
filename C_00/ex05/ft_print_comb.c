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

#include <unistd.h>

typedef struct s_data
{
	char	c;
	int		i;
	int		j;
	int		k;
}	t_data;

t_data	_init(void)
{
	t_data	res;

	res.c = '0';
	res.i = 0;
	res.j = 0;
	res.k = 0;
	return (res);
}

void	_print_seperator(t_data data)
{
	char	c;

	if (data.i == 7 && data.j == 8 && data.k == 9)
		return ;
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
	data.c = '0' + data.i;
	write(1, &data.c, 1);
	data.c = '0' + data.j;
	write(1, &data.c, 1);
	data.c = '0' + data.k;
	write(1, &data.c, 1);
	_print_seperator(data);
}

void	ft_print_comb(void)
{
	t_data	d;

	d = _init();
	while (d.i < 10)
	{
		d.j = d.i + 1;
		while (d.j < 10)
		{
			d.k = d.j + 1;
			while (d.k < 10)
			{
				_print(d);
				d.k++;
			}
			d.j++;
		}
		d.i++;
	}
}
