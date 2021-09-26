/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:26:41 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/27 00:11:23 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*_read_line(int fd, int size)
{
	int		index;
	char	*buffer;
	char	c;

	index = 0;
	if (size < 0)
		size = 2;
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	buffer[size] = '\0';
	if (!buffer)
		exit(1);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			buffer[index] = 0;
			break ;
		}
		if (index + 1 == size)
			buffer = ft_realloc(buffer, &size);
		buffer[index++] = c;
	}
	if (index == 0)
		return (free_buffer(buffer));
	return (buffer);
}

int	_set_map_info(t_input *input, char *line)
{
	int	size;

	size = ft_strlen(line);
	if (!line || size < 4)
		return (0);
	input->fill = line[size - 1];
	input->obstacle = line[size - 2];
	input->blank = line[size - 3];
	if ((input->fill == input->obstacle) || \
		(input->fill == input->blank) || \
		(input->obstacle == input->blank))
		return (0);
	line[size - 3] = '\0';
	input->n = ft_atoi(line);
	free(line);
	if (input->n == 0)
		return (0);
	return (1);
}

int	is_right_line(char *map, t_input *input)
{
	while (*map)
	{
		if ((*map != input->blank) && (*map != input->obstacle))
			return (0);
		map++;
	}
	return (1);
}

t_input	*_file_parser(int fd)
{
	t_input	*input;
	int		index;

	input = (t_input *)malloc(sizeof(t_input) * 1);
	_guard_input(input);
	if (!_set_map_info(input, _read_line(fd, -1)))
		return (_free_input(input, 0));
	input->map = (char **)malloc(sizeof(char *) * (input->n + 1));
	_guard_input_map(input->map);
	input->map[0] = _read_line(fd, -1);
	if (!input->map[0])
		return (_free_input(input, 0));
	input->m = ft_strlen(input->map[0]);
	index = 0;
	while (++index < input->n)
	{
		input->map[index] = _read_line(fd, input->m);
		if ((!input->map[index]) || \
		(!is_right_line(input->map[index], input)) || \
		(ft_strlen(input->map[index]) != input->m))
			return (_free_input(input, index + 1));
	}
	if (_read_line(fd, input->m))
		return (_free_input(input, input->n + 1));
	return (_get_input_close(input, fd));
}

t_input	*_file_open(char *str, int is_stdin)
{
	int	fd;

	if (is_stdin)
		return (_file_parser(0));
	else
	{
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (_put_error());
		return (_file_parser(fd));
	}
}
