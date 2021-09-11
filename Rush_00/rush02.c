/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:12:29 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/11 19:43:51 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char c);

typedef struct s_square
{
	int	i;
	int	j;
}	t_square;

t_square	_init(int w, int h)
{
	t_square	res;

	res.i = 0;
	res.j = 0;
	if (w <= 0 || h <= 0)
	{
		res.i = h;
		res.j = w;
	}
	else if (w > 2147483647 || h > 2147483647)
	{
		res.i = h;
		res.j = w;
	}
	return (res);
}

void	rush(int w, int h)
{
	t_square	s;

	s = _init(w, h);
	while (s.i < h)
	{
		s.j = 0;
		while (s.j < w)
		{
			if ((s.i == 0 && s.j == 0) || (s.i == 0 && s.j == w - 1))
				ft_putchar('A');
			else if (s.i == h - 1 && s.j == 0)
				ft_putchar('C');
			else if (s.i == h - 1 && s.j == w - 1)
				ft_putchar('C');
			else if (s.i == 0 || s.i == h - 1 || s.j == 0 || s.j == w - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			s.j++;
		}
		ft_putchar('\n');
		s.i++;
	}
}
