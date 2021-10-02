/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:26:41 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 12:02:41 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parser.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	_set_map_info(t_input *input, char *input_file, int line_cnt)
{
	int	n;
	int	ptr;
	int	index;

	ptr = 0;
	while (input_file[ptr] != '\n')
	{
		ptr++;
		if (!input_file[ptr])
			return (0);
	}
	if (ptr < 4 || !_set_info(input, input_file, &ptr))
		return (0);
	n = 0;
	index = 0;
	while (index < ptr)
	{
		n *= 10;
		n += input_file[index++] - '0';
	}
	if (n <= 0 || (n + 1) != line_cnt)
		return (0);
	input->n = n;
	return (1);
}

int	_get_file(char *file_name, char *max_buf)
{
	int	fd;
	int	i;

	if (!file_name)
	{
		i = 0;
		while (read(0, &max_buf[i], 1))
			i++;
	}
	else
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
			return (0);
		read(fd, max_buf, MAX_BUF);
		close(fd);
	}
	return (1);
}

t_input	*_set_map(t_input *input, char *input_file)
{
	char	*ptr;

	ptr = input_file;
	while (*ptr != '\n')
	{
		ptr++;
		if (!ptr)
		{
			_free_input(input);
			return (0);
		}
	}
	input->map = ft_split(ptr, "\n");
	free(input_file);
	input_file = 0;
	if (!_is_right_map(input))
	{
		_free_input(input);
		return (0);
	}
	else
		return (input);
}

t_input	*_parser(char *file_name)
{
	char	*max_buf;
	char	*input_file;
	t_input	*input;
	int		line_cnt;

	max_buf = (char *)malloc(sizeof(char) * (MAX_BUF));
	if (!max_buf)
		exit(1);
	if (!_get_file(file_name, max_buf))
		return (_free_str(max_buf));
	input_file = ft_strdup(max_buf);
	free(max_buf);
	input = (t_input *)malloc(sizeof(t_input) * 1);
	if (!input)
		_guard_str(input_file);
	input->size = ft_strlen(input_file);
	line_cnt = _count_line(input_file);
	if (!_set_map_info(input, input_file, line_cnt))
		return (_free_str_input(input_file, input));
	return (_set_map(input, input_file));
}

t_input	*_file_open(char *file_name, int is_stdin)
{
	if (is_stdin)
		return (_parser(0));
	else
		return (_parser(file_name));
}
