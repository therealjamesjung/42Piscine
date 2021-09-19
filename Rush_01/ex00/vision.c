/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 00:19:46 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 13:44:23 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	_check_row_l(int **map, t_data input, t_point pnt)
{
	int	i;
	int	cnt;
	int	tmp;

	cnt = 1;
	i = 0;
	tmp = map[pnt.y][i];
	while (i < input.n)
	{
		if (map[pnt.y][i] != 0)
		{
			if (map[pnt.y][i] > tmp)
			{
				tmp = map[pnt.y][i];
				cnt++;
			}
			if (map[pnt.y][i] == input.n)
				break;
			i++;
		}
		else
			return (1);
	}
	if (tmp == input.n && cnt != input.row_l[pnt.y])
		return (0);
	return (1);
}

int	_check_row_r(int **map, t_data input, t_point pnt)
{
	int	i;
	int	cnt;
	int	tmp;

	cnt = 1;
	i = input.n - 1;
	tmp = map[pnt.y][i];
	while (i >= 0)
	{
		if (map[pnt.y][i] != 0)
		{
			if (map[pnt.y][i] > tmp)
			{
				tmp = map[pnt.y][i];
				cnt++;
			}
			if (map[pnt.y][i] == input.n)
				break;
			i--;
		}
		else
			return (1);
	}
	if (tmp == input.n && cnt != input.row_r[pnt.y])
		return (0);
	return (1);
}

int	_check_col_u(int **map, t_data input, t_point pnt)
{
	int	i;
	int	cnt;
	int	tmp;

	cnt = 1;
	i = 0;
	tmp = map[i][pnt.x];
	while (i < input.n)
	{
		if (map[i][pnt.x] != 0)
		{
			if (map[i][pnt.x] > tmp)
			{
				tmp = map[i][pnt.x];
				cnt++;
			}
			if (map[i][pnt.x] == input.n)
				break;
			i++;
		}
		else
			return (1);
	}
	if (tmp == input.n && cnt != input.col_u[pnt.x])
		return (0);
	return (1);
}

int	_check_col_d(int **map, t_data input, t_point pnt)
{
	int	i;
	int	cnt;
	int	tmp;

	cnt = 1;
	i = input.n - 1;
	tmp = map[i][pnt.x];
	while (i >= 0)
	{
		if (map[i][pnt.x] != 0)
		{
			if (map[i][pnt.x] > tmp)
			{
				tmp = map[i][pnt.x];
				cnt++;
			}
			if (map[i][pnt.x] == input.n)
				break;
			i--;
		}
		else
			return (1);
	}
	if (tmp == input.n && cnt != input.col_d[pnt.x])
		return (0);
	return (1);
}

int _check_vis(int **map, t_data input, t_point pnt)
{
	if (!_check_col_u(map, input, pnt))
		return (0);
	if (!_check_col_d(map, input, pnt))
		return (0);
	if (!_check_row_l(map, input, pnt))
		return (0);
	if (!_check_row_r(map, input, pnt))
		return (0);
	return (1);
}