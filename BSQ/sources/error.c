/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:43:34 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 12:14:57 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdlib.h>

void	_free_all(int **map, t_input *input, int n)
{
	int	i;

	i = -1;
	if (map)
	{
		while (++i < n)
		{
			free(map[i]);
			map[i] = 0;
			free(input->map[i]);
			input->map[i] = 0;
		}
		free(map);
		map = 0;
	}
	if (input)
	{
		free(input->map);
		input->map = 0;
		free(input);
		input = 0;
	}
}

void	_free_input(t_input *input)
{
	int	i;

	i = -1;
	if (input->map)
	{
		while (input->map[++i])
		{
			free(input->map[i]);
			input->map[i] = 0;
		}
		free(input->map);
		input->map = 0;
	}
	if (input)
	{
		free(input);
		input = 0;
	}	
	write(2, "map error\n", 10);
}

t_input	*_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = 0;
	}
	write(2, "map error\n", 10);
	return (0);
}

t_input	*_free_str_input(char *input_file, t_input *input)
{
	if (input_file)
	{
		free(input_file);
		input_file = 0;
	}
	if (input)
	{
		_free_input(input);
		input = 0;
	}
	return (0);
}
