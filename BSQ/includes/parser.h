/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:38:21 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 11:14:32 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	_free_input(t_input *input);
void	_guard_str(char *str);
t_input	*_free_str_input(char *input_file, t_input *input);
char	**ft_split(char *str, char *charset);
t_input	*_free_str(char *str);
char	*ft_strdup(char *src);
int		_set_info(t_input *input, char *input_file, int *ptr);
int		_is_right_map(t_input *input);
int		ft_strlen(char *str);
int		_count_line(char *input_file);

#endif