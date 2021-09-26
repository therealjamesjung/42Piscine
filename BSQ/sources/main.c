/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:26:37 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/27 00:14:06 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	_get_answer(int **map, t_input *input, int is_end)
{
	_calc_map(map, input);
	_print_answer(_solve(map, input), input);
	if (!is_end)
		write(1, "\n", 1);
}

int	_check_input(t_input *input)
{
	if (input == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}

void	_run(int argc, char **argv)
{
	int		i;
	int		j;
	int		**map;
	t_input	*input;

	i = 0;
	while (++i < argc || argc == 1)
	{
		input = _file_open(argv[i], (argc == 1));
		if (!_check_input(input))
			continue ;
		map = (int **)malloc(sizeof(int *) * input->n);
		_guard_map(map, input, 0);
		j = -1;
		while (++j < input->n)
		{
			map[j] = (int *)malloc(sizeof(int) * input->m);
			_guard_map(map, input, j + 1);
		}
		_get_answer(map, input, (i == argc - 1));
		_free_all(map, input, input->n);
		if (argc == 1)
			break ;
	}
}

int	main(int argc, char **argv)
{
	_run(argc, argv);
	return (0);
}
