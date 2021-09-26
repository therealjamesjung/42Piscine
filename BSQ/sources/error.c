/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:43:34 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/26 23:34:45 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdlib.h>

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

t_input	*_free_input(t_input *input, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(input->map[i]);
	free(input->map);
	free(input);
	return (_put_error());
}
