/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:27:13 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 22:36:37 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "logic.h"
#include <stdlib.h>

int	**_copy_map(int **map, int n)
{
	int	**copied_map;
	int	x;
	int	y;

	y = -1;
	copied_map = (int **)malloc(sizeof(int *) * n);
	while (++y < n)
	{
		copied_map[y] = malloc(sizeof(int) * n);
		x = -1;
		while (++x < n)
			copied_map[y][x] = map[y][x];
	}
	return (copied_map);
}

int	***_copy_mtrx(int ***src, int n)
{
	int	***matrix;
	int	x;
	int	y;
	int	z;

	z = -1;
	matrix = (int ***)malloc(sizeof(int **) * n);
	while (++z < n)
	{
		matrix[z] = (int **)malloc(sizeof(int *) * n);
		y = -1;
		while (++y < n)
		{
			matrix[z][y] = (int *)malloc(sizeof(int) * n);
			x = -1;
			while (++x < n)
				matrix[z][y][x] = src[z][y][x];
		}
	}
	return (matrix);
}

t_point	_get_avbl_pnt(int ***matrix, int n)
{
	t_point	iter;
	t_point	tmp;
	int		cnt;

	iter.y = -1;
	while (++iter.y < n)
	{
		iter.x = -1;
		while (++iter.x < n)
		{
			iter.z = n;
			cnt = 0;
			while (--iter.z >= 0)
			{
				if (matrix[iter.z][iter.y][iter.x] != -1)
				{
					tmp = _create_pnt(iter.z, iter.y, iter.x, iter.z + 1);
					cnt++;
				}
			}
			if (cnt == 1)
				return (tmp);
		}
	}
	return (_create_pnt(-1, -1, -1, -1));
}

void	_update(int ***map, int ****matrix, t_data input, int n)
{
	t_point	tmp;

	while (1)
	{
		tmp = _get_avbl_pnt(matrix[0], n);
		if (tmp.value == -1)
			break ;
		else
		{
			matrix[0][tmp.z][tmp.y][tmp.x] = -1;
			map[0][tmp.y][tmp.x] = tmp.value;
			if (_check_vis(map[0], input, tmp))
				_fix_pos(matrix[0], tmp, n);
			else
				map[0][tmp.y][tmp.x] = 0;
		}
	}
}

int	_solve(int **map, int ***matrix, t_data input, t_point pnt)
{
	t_point	tmp;
	int		**new_map;
	int		***new_mtrx;

	new_mtrx = _copy_mtrx(matrix, input.n);
	new_map = _copy_map(map, input.n);
	new_mtrx = _fix_pos(new_mtrx, pnt, input.n);
	if (!_check_vis(new_map, input, pnt))
		return (0);
	_update(&new_map, &new_mtrx, input, input.n);
	if (_check_map(new_map, input.n))
		return (_print_map(new_map, input.n));
	while (1)
	{
		tmp = _get_next_pnt(new_mtrx, input.n);
		if (tmp.value == -1)
			return (0);
		new_mtrx[tmp.z][tmp.y][tmp.x] = -1;
		new_map[tmp.y][tmp.x] = tmp.value;
		if (!_solve(new_map, new_mtrx, input, tmp))
			new_map[tmp.y][tmp.x] = 0;
		else
			return (1);
	}
}
