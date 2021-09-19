/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:29:35 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 21:12:35 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdlib.h>

int		***_create_matrix(int n);
int		**_init_map(int **map, t_data input, int ****matrix, int n);
int		_verify_input(t_data input);
t_data	_init_input(char *input, int n, int index);
int		**_create_map(int n);
int		_check_input(int argc, char **argv, int n);
int		_check_vis(int **map, t_data input, t_point pnt);
t_point	_create_pnt(int z, int y, int x, int value);
t_point	_get_avbl_pnt(int ****matrix, int n);
int		***_fix_pos(int ***matrix, t_point point, int n);
void	_print_map(int **map, int n);
void	_print_matrix(int ***matrix, int n);
t_point	_get_next_pnt(int ***m, int n);
int		_solve(int **map, int ***matrix, t_data input, t_point pnt);

int	main(int argc, char **argv)
{
	int		n;
	t_data	input;
	int		**map;
	int		***matrix;

	n = 4;
	matrix = _create_matrix(n);
	map = _create_map(n);
	if (!_check_input(argc, argv, n))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input = _init_input(argv[1], n, 0);
	if (!_verify_input(input))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	map = _init_map(map, input, &matrix, n);
	if (!_solve(map, matrix, input, _create_pnt(0, 0, 0, -1)))
		write(1, "Error\n", 6);
	return (0);
}
