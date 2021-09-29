/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:43:34 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 04:14:46 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdlib.h>

void	_free_all(int **map, t_input *input, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		free(map[i]);
		free(input->map[i]);
	}
	free(map);
	free(input->map);
	free(input);
}

void	_free_input(t_input *input)
{
	int	i;

	i = -1;
	if (input->map)
	{
		while (input->map[++i])
			free(input->map[i]);
	}
	free(input->map);
	free(input);
	write(2, "map error", 9);
}

t_input	*_free_str(char *str)
{
	free(str);
	write(2, "map error", 9);
	return (0);
}

t_input	*_free_str_input(char *input_file, t_input *input)
{
	free(input_file);
	_free_input(input);
	return (0);
}
