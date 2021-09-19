/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:50:31 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 22:27:16 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H

# define LOGIC_H
# include "data.h"

t_point	_get_next_pnt(int ***m, int n);
t_point	_create_pnt(int z, int y, int x, int value);
int		_check_vis(int **map, t_data input, t_point pnt);
int		***_fix_pos(int ***matrix, t_point point, int n);
int		_check_map(int **map, int n);
int		_print_map(int **map, int n);

#endif