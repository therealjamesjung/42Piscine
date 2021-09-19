/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:29:35 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 22:33:34 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "main.h"
#include <unistd.h>

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
