/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:19:30 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 22:00:29 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "matrix.h"
#include <stdlib.h>

int	***_create_matrix(int n)
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
				matrix[z][y][x] = z + 1;
		}
	}
	return (matrix);
}

int	***_fix_pos(int ***matrix, t_point point, int n)
{
	int	i;

	if (point.value == -1)
		return (matrix);
	i = 0;
	while (i < n)
		matrix[i++][point.y][point.x] = -1;
	i = 0;
	while (i < n)
		matrix[point.value - 1][i++][point.x] = -1;
	i = 0;
	while (i < n)
		matrix[point.value - 1][point.y][i++] = -1;
	return (matrix);
}

t_point	_get_next_pnt(int ***m, int n)
{
	int	i;
	int	j;
	int	k;

	i = n;
	while (--i >= 0)
	{
		j = -1;
		while (++j < n)
		{
			k = -1;
			while (++k < n)
			{
				if (m[i][j][k] != -1)
					return (_create_pnt(i, j, k, i + 1));
			}
		}
	}
	return (_create_pnt(-1, -1, -1, -1));
}
