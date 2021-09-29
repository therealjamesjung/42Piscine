/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:26:41 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/30 02:51:49 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
char	**ft_split(char *str, char *charset);
t_input *_free_str(char *str);
char	*ft_strdup(char *src);


void	_test_put_inputs(char **inputs)
{
	int	i;

	i = 0;
	while (inputs[i])
	{
		printf("inputs[%d] : %s\n", i, inputs[i]);
		i++;
	}
}

int	_set_map_info(t_input *input, char *input_file)
{
	int	n;
	int	ptr;
	int index;
	ptr = 0;
	while (input_file[ptr] != '\n')
	{
		ptr++;
		if (!input_file[ptr])
			return (0);
	}
	if (ptr < 4)
		return (0); // map error
	input->fill = input_file[--ptr];
	input->obstacle = input_file[--ptr];
	input->blank = input_file[--ptr];
	if ((input->fill == input->obstacle) || \
		(input->fill == input->blank) || \
		(input->obstacle == input->blank))
		return (0); // map error
	n = 0;
	index = 0;
	while (index < ptr)
	{
		n *= 10;
		n += input_file[index++] - '0';
	}
	if (n <= 0)
		return (0); // map error
	input->n = n;
	return (1);
}

int	_is_right_line(t_input *input, int inx, int len)
{
	int	i;
	char	c;

	i = 0;
	while (input->map[inx][i]) // split에서 각 문자열에 '\0'없으면 에러
	{
		c = input->map[inx][i];
		if (c != input->blank && c != input->obstacle)
			return (0);
		i++;
	}
	if (i != len)
		return (0);
	input->m = len;
	return (1);
}

int	_is_right_map(t_input *input)
{
	int	i;
	int	len;

	if (!input->map[0])
		return (0);
	len = ft_strlen(input->map[0]);
	i = 0;
	while (input->map[i])
	{
		if (!_is_right_line(input, i, len))
			return (0);
		i++;
	}
	if (i != input->n)
		return (0);
	return (1);
}

int	_get_file(char *file_name, char *max_buf)
{
	int	fd;
	int	i;
	
	if (!file_name)
		fd = 0;
	else
		fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	read(fd, max_buf, MAX_BUF);
	close(fd);
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

	max_buf = (char *)malloc(sizeof(char) * (MAX_BUF));
	if(!max_buf)
		return (0);
	if(!_get_file(file_name, max_buf))
		return (_free_str(max_buf)); // map error
	
	input_file = ft_strdup(max_buf);
	printf("%s\n", input_file);
	while (1)
	{
		;
	}
	free(max_buf);
	input = (t_input *)malloc(sizeof(t_input) * 1);
	input->size = ft_strlen(input_file);
	if(!input)
		_guard_str(input_file); //null guard
	if (!_set_map_info(input, input_file))
		return (_free_str_input(input_file, input)); // map error
	return (_set_map(input, input_file));
}

t_input	*_file_open(char *file_name, int is_stdin)
{
	if (is_stdin)
		return (_parser(0));
	else
		return (_parser(file_name));
}
