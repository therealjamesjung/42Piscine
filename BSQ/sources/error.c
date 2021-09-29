/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:43:34 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/28 18:19:19 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_input	*_put_error(void)
{
	write(2, "map error\n", 10);
	return (0);
}

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

t_input	*_free_map(int **map, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(map[i]);
	free(map);
	return (_put_error());
}

t_input	*_free_input(t_input *input, char **inputs, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(input->map[i]);
	i = -1;
	while (++i < input->n + 1)
		free(inputs[i]);
	free(input->map);
	free(input);
	free(inputs);
	return (_put_error());
}

t_input *_free_input_file(char *input)
{
	free(input);
	return (0);
}
t_input *_free_inputs(char **inputs, t_input *input)
{
	int	i;

	i = -1;
	while(++i < input->n + 1)
		free(inputs[i]);
	free(inputs);
	return (input);
}