/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:27:44 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/18 20:47:32 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		***_fix_pos(int ***matrix, t_point point, int n);
t_point	_create_pnt(int x, int y, int value);

int	_check_fixable(int a, int b, int n)
{
	if (a == n && b == 1)
		return (1);
	else if (a == 1 && b == n)
		return (-1);
	return (0);
}

int	**_create_map(int n)
{
	int	**map;
	int	i;

	i = 0;
	map = (int **)malloc(sizeof(int *) * n);
	while (i < n)
		map[i++] = (int *)malloc(sizeof(int) * n);
	return (map);
}

void	_fix_answer(int ***map, int ****m, t_data input, int i)
{
	int	j;
	int	flag;
	int	n;

	n = input.n;
	j = -1;
	flag = _check_fixable(input.col_u[i], input.col_d[i], n);
	if (flag != 0)
	{
		while (++j < n)
		{
			map[0][j][i] = ((n + 1 + (j + 1) * flag) % (n + 1));
			*m = _fix_pos(*m, _create_pnt(j, i, map[0][j][i]), n);
		}
	}
	j = -1;
	flag = _check_fixable(input.row_l[i], input.row_r[i], n);
	if (flag != 0)
	{
		while (++j < n)
		{
			map[0][i][j] = (n + 1 + (j + 1) * flag) % (n + 1);
			*m = _fix_pos(*m, _create_pnt(i, j, map[0][i][j]), n);
		}
	}
}

int	**_init_answer(int **map, t_data input, int ****matrix, int n)
{
	int	i;
	int	flag;

	i = -1;
	while (++i < n)
	{
		_fix_answer(&map, matrix, input, i);
	}
	return (map);
}
