/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:29:35 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/18 20:54:43 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	***_create_matrix(int n);
int	**_init_answer(int **map, t_data input, int ****matrix, int n);
int _verify_input(t_data input);
t_data _init(char *input, int n, int index);
int	**_create_map(int n);
int _check_input(int argc, char **argv, int n);

void _print_matrix(int ***matrix, int n)
{
	int i,j,k;

	for (i=0; i<n; i++)
	{
		printf("%dth floor\n", i);
		for (j=0; j<n; j++)
		{
			for (k=0; k<n; k++)
				printf("%d ",matrix[i][j][k]);
			printf("\n");
		}
	}
}

int main(int argc, char **argv)
{
	int i, j, n;
	t_data input;
	t_point point;
	int **map;
	int ***matrix;
	
	n = 4;	
	matrix = _create_matrix(n);
    map = _create_map(n);
	if (!_check_input(argc, argv, n))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input = _init(argv[1], n, -1);

	if (!_verify_input(input))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("hi!");


	map = _init_answer(map, input, &matrix, n);

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	_print_matrix(matrix, n);
	return (0);
}