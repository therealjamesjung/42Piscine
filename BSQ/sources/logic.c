/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:25:36 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 10:48:34 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "logic.h"
#include <stdlib.h>
#include <unistd.h>

void	_calc_map(int **map, t_input *input)
{
	int	i;
	int	j;
	int	obs_cnt;

	i = -1;
	while (++i < input->n)
	{
		j = -1;
		while (++j < input->m)
		{
			obs_cnt = 0;
			if (i > 0)
				obs_cnt += map[i - 1][j];
			if (j > 0)
				obs_cnt += map[i][j - 1];
			if (i > 0 && j > 0)
				obs_cnt -= map[i - 1][j - 1];
			obs_cnt += (input->map[i][j] == input->obstacle);
			map[i][j] = obs_cnt;
		}
	}
}

int	_fit_square(int **map, int max_side, int y, int x)
{
	int	top_l;
	int	top_r;
	int	bot_l;
	int	bot_r;

	top_l = 0;
	top_r = 0;
	bot_l = 0;
	if (x > 0 && y > 0)
		top_l = map[y - 1][x - 1];
	if (y > 0)
		top_r = map[y - 1][x + max_side];
	if (x > 0)
		bot_l = map[y + max_side][x - 1];
	bot_r = map[y + max_side][x + max_side];
	if (bot_l + top_r - top_l == bot_r)
		return (1);
	else
		return (0);
}

t_answer	_solve(int **map, t_input *input)
{
	t_answer	answer;
	int			max_side;
	int			i;
	int			j;

	max_side = 0;
	answer = _create_answer(0, -1, -1);
	i = -1;
	while (++i < input->n - max_side)
	{
		j = -1;
		while (++j < input->m - max_side)
		{
			while (1)
			{
				if (i + max_side >= input->n || j + max_side >= input->m)
					break ;
				if (input->map[i][j] == input->obstacle || \
					_fit_square(map, max_side, i, j) == 0)
					break ;
				answer = _create_answer(max_side++, i, j);
			}
		}
	}
	return (answer);
}

char	_get_char(t_answer answer, t_input *input, int i, int j)
{
	char	c;

	if (input->map[i][j] == input->obstacle)
		c = (unsigned char) input->obstacle;
	else
	{
		if ((i >= answer.top_l.y && i <= answer.bot_l.y) && \
			(j >= answer.top_l.x && j <= answer.top_r.x))
			c = (unsigned char) input->fill;
		else
			c = (unsigned char) input->blank;
	}
	return (c);
}

void	_print_answer(t_answer answer, t_input *input)
{
	int				i;
	int				j;
	unsigned char	c;
	char			*ret;
	int				size;

	size = 0;
	i = -1;
	ret = (char *)malloc(sizeof(char) * (input->size));
	if (!ret)
		_guard_input(input);
	while (++i < input->n)
	{
		j = -1;
		while (++j < input->m)
		{
			c = _get_char(answer, input, i, j);
			ret[size++] = c;
		}
		ret[size++] = '\n';
	}
	write(1, ret, size);
	free(ret);
}
