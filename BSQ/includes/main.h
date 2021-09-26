/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:38:13 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/26 23:38:14 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

void		_print_answer(t_answer answer, t_input *input);
t_answer	_solve(int **map, t_input *input);
void		_calc_map(int **map, t_input *input);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
int			is_number(char c);
int			is_operator(char c);
int			is_space(char c);
void		ft_strcpy(char *dest, char *src);
t_input		*_file_open(char *str, int is_stdin);
void		_free_all(int **map, t_input *input, int n);
void		_guard_map(int **map, t_input *input, int index);

#endif