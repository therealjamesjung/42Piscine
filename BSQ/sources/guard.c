/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guard.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:26:59 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 04:19:42 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdlib.h>
#include <unistd.h>

t_input	*_free_input(t_input *input, int n);
void	_free_all(int **map, t_input *input, int n);
t_input	*_free_map(int **map, int n);

void	_guard_map(int **map, t_input *input, int index)
{
	if (!map)
	{
		_free_all(map, input, index);
		exit(1);
	}
}

void	_guard_input(t_input *input)
{
	if (!input)
	{
		free(input);
		exit(1);
	}
}

void	_guard_input_map(char **map)
{
	if (!map)
	{
		free(map);
		exit(1);
	}
}

t_input	*_get_input_close(t_input *input, int fd)
{
	close(fd);
	return (input);
}

void	_guard_str(char *str)
{
	free(str);
	exit(1);
}
