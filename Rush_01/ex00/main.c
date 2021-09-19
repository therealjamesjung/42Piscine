/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:29:35 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 15:34:09 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	***_create_matrix(int n);
int	**_init_map(int **map, t_data input, int ****matrix, int n);
int _verify_input(t_data input);
t_data _init_input(char *input, int n, int index);
int	**_create_map(int n);
int _check_input(int argc, char **argv, int n);
int _check_vis(int **map, t_data input, t_point pnt);
t_point	_create_pnt(int z, int y, int x, int value);
t_point _get_avbl_pnt(int ****matrix, int n);
int	***_fix_pos(int ***matrix, t_point point, int n);
void _print_map(int **map, int n);
void _print_matrix(int ***matrix, int n);
t_point _get_next_pnt(int ***m, int n);
void _solve(int **map, int ***matrix, t_data input, int cnt);

int main(int argc, char **argv)
{
	int i, n;
	t_data input;
	//_point point;
	int **map;
	int ***matrix;
	
	n = 4;	
	matrix = _create_matrix(n);
    map = _create_map(n);
	if (!_check_input(argc, argv, n))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input = _init_input(argv[1], n, 0);
	
	printf("Input\n");
	for (i=0; i<n; i++)
	{
		printf("%d ", input.col_u[i]);
		printf("%d ", input.col_d[i]);
		printf("%d ", input.row_l[i]);
		printf("%d \n", input.row_r[i]);
	}
	if (!_verify_input(input))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("AA\n");
	map = _init_map(map, input, &matrix, n);
	printf("AA\n");
	/*
	map[0][0] = 4;
	map[1][0] = 1;
	map[2][0] = 3;
	map[3][0] = 2;
	map[0][1] = 1;
	map[1][1] = 4;
	map[2][1] = 2;
	map[3][1] = 3;
	map[0][2] = 2;
	map[1][2] = 3;
	map[2][2] = 1;
	map[3][2] = 4;
	map[0][3] = 3;
	map[1][3] = 2;
	map[2][3] = 4;
	map[3][3] = 1;
	
	_check_vis(map, input, _create_pnt(-1, 1, 0, -1));
	*/
	_solve(map, matrix, input, 0);
	/*
	printf("Map\n");
	_print_map(map, n);
	printf("Matrix\n");
	_print_matrix(matrix, n);
	*/
	return (0);
}