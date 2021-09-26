/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:28:30 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/26 21:01:20 by jaekjung         ###   ########.fr       */
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

char	*ft_realloc(char *buffer, int *size)
{
	char	*new_buffer;

	*size *= 2;
	new_buffer = (char *)malloc(sizeof(char) * (*size + 1));
	if (!new_buffer)
		exit(1);
	ft_strncpy(new_buffer, buffer, *size);
	free_buffer(buffer);
	return (new_buffer);
}
