/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:29:39 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 22:24:58 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdlib.h>

int	_check_input(int argc, char **argv, int n)
{
	int		cnt;
	char	*tmp;

	cnt = 0;
	tmp = argv[1];
	if (argc != 2)
		return (0);
	while (*tmp != '\0')
	{
		if ((*tmp < '0' || *tmp > '0' + n) && *tmp != ' ')
			return (0);
		else if (*tmp >= '1' && *tmp <= '0' + n)
			cnt++;
		tmp++;
	}
	if (cnt != n * 4)
		return (0);
	return (1);
}

t_data	_init_input(char *input, int n, int i)
{
	t_data	new_data;

	new_data.col_u = (int *)malloc(sizeof(int) * n);
	new_data.col_d = (int *)malloc(sizeof(int) * n);
	new_data.row_l = (int *)malloc(sizeof(int) * n);
	new_data.row_r = (int *)malloc(sizeof(int) * n);
	new_data.n = n;
	while (*input != '\0')
	{
		if (*input < '1' || *input > '0' + n)
		{
			input++;
			continue ;
		}
		if (i / n == 0)
			new_data.col_u[i++ % n] = *input - '0';
		else if (i / n == 1)
			new_data.col_d[i++ % n] = *input - '0';
		else if (i / n == 2)
			new_data.row_l[i++ % n] = *input - '0';
		else if (i / n == 3)
			new_data.row_r[i++ % n] = *input - '0';
		input++;
	}
	return (new_data);
}

int	_verify_input(t_data input, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		if ((input.col_d[index] + input.col_u[index] > n + 1) || \
			(input.col_d[index] + input.col_u[index] < 3))
			return (0);
		if ((input.row_l[index] + input.row_r[index] > n + 1) || \
			(input.row_l[index] + input.row_r[index] < 3))
			return (0);
		index++;
	}
	return (1);
}

t_point	_create_pnt(int z, int y, int x, int value)
{
	t_point	new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	new_point.value = value;
	return (new_point);
}

int	_check_fixable(int a, int b, int n)
{
	if (a == n && b == 1)
		return (1);
	else if (a == 1 && b == n)
		return (-1);
	return (0);
}
