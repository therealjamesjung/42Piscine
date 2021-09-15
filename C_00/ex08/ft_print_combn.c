/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:25:03 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/15 12:46:49 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_print_int(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}

void	_print_seperator(int *arr, int size)
{
	int	i;
	int	flag;

	flag = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (arr[i] != 10 - size + i)
		{
			flag = 1;
		}
		i--;
	}
	if (flag == 1)
		write(1, ", ", 2);
}

void	_print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		_print_int(arr[i]);
		i++;
	}
	_print_seperator(arr, size);
}

void	comb(int *arr, int size, int idx, int r)
{
	int	i;

	i = 0;
	if (r == 0)
	{
		_print_arr(arr, size);
		return ;
	}
	while (i + idx < 10)
	{
		arr[size++] = i + idx;
		comb(arr, size, i + idx + 1, r - 1);
		size--;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	comb(arr, 0, 0, n);
}
