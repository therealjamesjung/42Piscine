/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:48:38 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 21:54:06 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H
# include "data.h"

int		***_fix_pos(int ***matrix, t_point point, int n);
t_point	_create_pnt(int z, int y, int x, int value);
int		_check_fixable(int a, int b, int n);

#endif