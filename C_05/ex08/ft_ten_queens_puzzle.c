/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:07:24 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/22 02:11:43 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_print_board(int *board)
{
	int		i;
	char	c;

	i = -1;
	while (++i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	_validate_board(int *board, int column)
{
	int	i;

	i = -1;
	while (++i < column)
	{
		if (board[column] == board[i])
			return (0);
		else if (board[column] - board[i] == column - i)
			return (0);
		else if (board[i] - board[column] == column - i)
			return (0);
	}
	return (1);
}

void	_solve(int *board, int column, int *count)
{
	board[column] = -1;
	while (++board[column] < 10)
	{
		if (_validate_board(board, column))
		{
			if (column == 9)
			{
				_print_board(board);
				(*count)++;
			}
			else
				_solve(board, column + 1, count);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	cnt;

	cnt = 0;
	_solve(board, 0, &cnt);
	return (cnt);
}
