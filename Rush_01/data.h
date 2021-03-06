/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 00:19:56 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 21:45:03 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	int	*col_u;
	int	*col_d;
	int	*row_l;
	int	*row_r;
	int	n;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	value;
}	t_point;

#endif