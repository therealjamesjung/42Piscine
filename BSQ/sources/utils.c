/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:28:30 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 11:13:57 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

t_point	_create_pnt(int y, int x)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_answer	_create_answer(int max_side, int y, int x)
{
	t_answer	answer;

	answer.top_l = _create_pnt(y, x);
	answer.top_r = _create_pnt(y, x + max_side);
	answer.bot_l = _create_pnt(y + max_side, x);
	answer.bot_r = _create_pnt(y + max_side, x + max_side);
	return (answer);
}

char	*free_buffer(char *buffer)
{
	free(buffer);
	return (0);
}

int	_count_line(char *input_file)
{
	int	cnt;
	int	index;

	index = 0;
	cnt = 0;
	while (input_file[index] != '\0')
	{
		if (input_file[index] == '\n')
			cnt++;
		index++;
	}
	return (cnt);
}
