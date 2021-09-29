/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:38:21 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 02:27:52 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char	*ft_realloc(char *buffer, int *size);
char	*free_buffer(char *buffer);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
t_input	*_put_error(void);
void	_free_input(t_input *input);
void	_guard_input_map(char **map);
void	_guard_input(t_input *input);
t_input	*_get_input_close(t_input *input, int fd);
void	_guard_str(char *str);
t_input	*_free_str_input(char *input_file, t_input *input);

#endif