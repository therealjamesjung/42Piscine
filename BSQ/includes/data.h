/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:25:40 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 11:49:16 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_answer
{
	t_point	top_l;
	t_point	top_r;
	t_point	bot_l;
	t_point	bot_r;
}	t_answer;

typedef struct s_input
{
	char	**map;
	char	blank;
	char	obstacle;
	char	fill;
	int		n;
	int		m;
	int		size;
}	t_input;

# define MAX_BUF 2147483647

#endif