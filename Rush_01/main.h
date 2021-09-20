/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:45:36 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/19 22:04:57 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H 
# include "data.h"

int		***_create_matrix(int n);
int		**_create_map(int n);
int		_check_input(int argc, char **argv, int n);
int		_verify_input(t_data input);
int		**_init_map(int **map, t_data input, int ****matrix, int n);
int		_solve(int **map, int ***matrix, t_data input, t_point pnt);
t_data	_init_input(char *input, int n, int index);
t_point	_create_pnt(int z, int y, int x, int value);

#endif