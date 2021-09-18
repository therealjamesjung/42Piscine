/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:29:39 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/18 20:53:02 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int _check_input(int argc, char **argv, int n)
{
	int		cnt;
	char	*tmp;
	
	cnt = 0;
	tmp = argv[1];
	if (argc != 2)
		return (0);
	while (*tmp != '\0')
	{
		if ((*tmp < '0' || *tmp > '0' + n ) && *tmp != ' ')
			return (0);
		else if (*tmp >= '1' && *tmp <= '0' + n)
			cnt++;
		tmp++;
	}

	printf("count is %d\n", cnt);
	if (cnt != n * n)
		return (0);

	return (1);
}

t_data _init(char *input, int n, int index)
{
	t_data new_data;

	new_data.col_u = (int *)malloc(sizeof(int) * n);
	new_data.col_d = (int *)malloc(sizeof(int) * n);
	new_data.row_l = (int *)malloc(sizeof(int) * n);
	new_data.row_r = (int *)malloc(sizeof(int) * n);
	new_data.n = n;
	while (++index < n * n)
	{
		if (*input < '1' || *input > '0' + n)
		{
			input++;
			continue;
		}
		if (index / n == 0)
			new_data.col_u[index % n] = *input - '0';
		else if (index / n == 1)
			new_data.col_d[index % n] = *input - '0';
		else if (index / n == 2)
			new_data.row_l[index % n] = *input - '0';
		else if (index / n == 3)
			new_data.row_r[index % n] = *input - '0';
		input++;
	}
	return (new_data);
}

int _verify_input(t_data input)
{
	int index;

	index = 0;
	while(index < input.n)
	{
		if((input.col_d[index] + input.col_u[index] > input.n + 1) || (input.col_d[index] + input.col_u[index] < 3))
			return (0);
		if((input.row_l[index] + input.row_r[index] > input.n + 1) || (input.row_l[index] + input.row_r[index] < 3))
			return (0);	
		index++;
	}
	return (1);
}

t_point _create_pnt(int y, int x, int value)
{
	t_point new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.value = value;
	return (new_point);
}