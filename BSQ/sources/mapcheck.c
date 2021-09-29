/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 03:21:17 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 03:39:26 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mapcheck.h"

int	_is_right_line(t_input *input, int inx, int len)
{
	int		i;
	char	c;

	i = 0;
	while (input->map[inx][i])
	{
		c = input->map[inx][i];
		if (c != input->blank && c != input->obstacle)
			return (0);
		i++;
	}
	if (i != len)
		return (0);
	input->m = len;
	return (1);
}

int	_is_right_map(t_input *input)
{
	int	i;
	int	len;

	if (!input->map[0])
		return (0);
	len = ft_strlen(input->map[0]);
	i = 0;
	while (input->map[i])
	{
		if (!_is_right_line(input, i, len))
			return (0);
		i++;
	}
	if (i != input->n)
		return (0);
	return (1);
}

int	_set_info(t_input *input, char *input_file, int *ptr)
{
	(*ptr)--;
	input->fill = input_file[*ptr];
	(*ptr)--;
	input->obstacle = input_file[*ptr];
	(*ptr)--;
	input->blank = input_file[*ptr];
	if ((input->fill == input->obstacle) || (input->fill == input->blank) || \
		(input->obstacle == input->blank))
		return (0);
	return (1);
}
