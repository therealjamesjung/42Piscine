/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:27:13 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 20:52:49 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

t_point _get_next_pnt(int ***m, int n);
t_point	_create_pnt(int z, int y, int x, int value);
int _check_vis(int **map, t_data input, t_point pnt);
int	***_fix_pos(int ***matrix, t_point point, int n);
int _check_map(int **map, int n);
void _print_map(int **map, int n);
void _print_matrix(int ***matrix, int n);

int **_copy_map(int **map, int n)
{
	int **copied_map;
	int x;
	int y;

	y = -1;
	copied_map = (int **)malloc(sizeof(int*) * n);
	while(++y < n)
	{
		copied_map[y] = malloc(sizeof(int) * n);
		x = -1;
		while(++x < n)
			copied_map[y][x] = map[y][x];
	}
	return (copied_map);
}

int ***_copy_mtrx(int ***src, int n)
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

t_point _get_avbl_pnt(int ***matrix, int n)
{
	int i;
	int j;
	int k;
	int cnt;
	t_point tmp;

	j = -1;
	while (++j < n)
	{
		k = -1;
		while (++k < n)
		{
			i = n;
			cnt = 0;
			while (--i >= 0)
				if (matrix[i][j][k] != -1)
				{
					tmp = _create_pnt(i, j, k, i + 1);
					cnt++;
				}
			if (cnt == 1)
				return (tmp);
		}
	}
	return (_create_pnt(-1, -1, -1, -1));
}

void _update(int ***map, int ****matrix, t_data input, int n)
{
	t_point tmp;

	while (1)
	{
		// _print_matrix(matrix, n);
		tmp = _get_avbl_pnt(matrix[0], n);
		printf("Updated Map:\n");
		_print_map(map[0], n);
		printf("~~~~~~~~~~~~~~\n");
		if (tmp.value == -1)
			break;
		else
		{
			printf("Updated position: %d %d %d %d\n", tmp.z, tmp.y, tmp.x, tmp.value);

			matrix[0][tmp.z][tmp.y][tmp.x] = -1;
			map[0][tmp.y][tmp.x] = tmp.value;
			if (_check_vis(map[0], input, tmp)) // if vision check is passed
				_fix_pos(matrix[0], tmp, n);
			else // Error on vision check i.e. map is a WRONG ANSWER
			{
				map[0][tmp.y][tmp.x] = 0;
			}
		}
	}
}

int _check_updatable(int **map, int ***matrix, int n)
{
	int i;
	int j;
	int k;
	int cnt;

	j = -1;
	while (++j < n)
	{
		k = -1;
		while (++k < n)
		{
			cnt = 0;
			i = -1;
			while (++i < n)
			{
				if (matrix[i][j][k] != -1)
					cnt++;
				if (cnt == 0 && map[j][k] == 0) return (0);
			}
		}
	}
	return (1);
}

int _solve(int **map, int ***matrix, t_data input, t_point pnt, int cnt)
{
	t_point tmp;
	int **new_map;
	int ***new_mtrx;
	
	new_mtrx = _copy_mtrx(matrix, input.n);
	new_map = _copy_map(map, input.n);
	new_mtrx = _fix_pos(new_mtrx, pnt, input.n);

	printf("-----------------\n");
	printf("Depth: %d\n", cnt);
	printf("-----------------\n");
	printf("Point\n");
	printf("z: %d y: %d x: %d val: %d\n", pnt.z, pnt.y, pnt.x, pnt.value);
	printf("-----------------\n");
	printf("Map\n");
	_print_map(new_map, input.n);
	printf("-----------------\n");
	printf("Matrix\n");
	printf("-----------------\n");
	_print_matrix(new_mtrx, input.n);
	printf("-----------------\n\n");

	if (!_check_vis(new_map, input, pnt))
	{
		printf("Vision Error on depth: %d\n", cnt);
		return (0);
	}
	/*
	if (!_check_updatable(new_map, new_mtrx, input.n))
	{
		printf("Updatability Error on depth %d\n", cnt);
		return (0);
	}
	*/
	printf("Update Start!\n");
	_update(&new_map, &new_mtrx, input, input.n);
	printf("Update End\n");
	if (_check_map(new_map, input.n))
	{
		printf("\n@@@@@@@@@@@@@@@@@@@@@\n");
		_print_map(new_map, input.n);
		printf("\n@@@@@@@@@@@@@@@@@@@@@\n");
		return (1);
	}

	// Vis check pass , updateable pass , update but still answer X
	while (1)
	{
		tmp = _get_next_pnt(new_mtrx, input.n);
		printf("Next Value on depth %d is z: %d y: %d x: %d val: %d \n", cnt, tmp.z, tmp.y, tmp.x, tmp.value);
		if (tmp.value == -1)
			return (0);
		new_mtrx[tmp.z][tmp.y][tmp.x] = -1;
		new_map[tmp.y][tmp.x] = tmp.value;
		if (!_solve(new_map, new_mtrx, input, tmp, cnt + 1))
			new_map[tmp.y][tmp.x] = 0;
		else
			return (1);
	}
}