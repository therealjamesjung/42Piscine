/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:26:41 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/28 18:17:53 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
char	**ft_split(char *str, char *charset);
t_input *_free_input_file(char *inputs);
t_input *_free_inputs(char **inputs, t_input *input);
char	*ft_strdup(char *src);

char	*_read_line(char **inputs, int inx, int n)
{
	if (inx < n + 1)
		return (ft_strdup(inputs[inx]));
	else
		return (0);
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
		return (0); // TODO 라인 ;;
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

int	_get_file_size(int fd)
{
	int	size;
	char	c;

	size = 0;
	while (read(fd, &c, 1))
		size++;
	return (size);
}

int	_get_file(char *file_name, int file_size, char *input_file)
{
	int	fd;
	int	i;
	
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	read(fd, input_file, file_size);
	close(fd);
	return (1);
}

t_input	*_set_map(t_input *input, char **inputs)
{
	int	index;

	printf("input->n : %d\n", input->n);

	input->map = (char **)malloc(sizeof(char *) * (input->n + 1));
	_guard_input_map(input->map);
	input->map[0] = _read_line(inputs, 1, input->n);
	if (!input->map[0])
		return (_free_input(input, inputs, 0)); // ?
	input->m = ft_strlen(input->map[0]);
	index = 0;
	// printf("index : %d\n%s\n", index, input->map[index]);
	while (++index < input->n)
	{
		input->map[index] = _read_line(inputs, index + 1, input->n);
		printf("index : %d\n%s\n", index, input->map[index]);
		if ((!input->map[index]) || \
		(!is_right_line(input->map[index], input)) || \
		(ft_strlen(input->map[index]) != input->m))
			return (_free_input(input, inputs, index + 1)); // ?
	}
	printf("-------------------------------------\n");
	printf("%d\n", index + 1);
	printf("%s\n", _read_line(inputs, index, input->n));
	if (!_read_line(inputs, index + 1, input->n))
	{
		printf("Input has more line than expected.\n");
		return (_free_input(input, inputs, input->n + 1)); // ?
	}
	_free_inputs(inputs, input);
	return (input);
}

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

t_input	*_new_parser(char *file_name)
{
	int	file_size;
	int	fd;
	char	*input_file;
	char	**inputs;
	t_input	*input;

	if (file_name)
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
			return (0);
	}
	else
		fd = 0;
	file_size = _get_file_size(fd);
	close(fd);
	printf("file_size : %d\n", file_size);
	
	input_file = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!input_file)
		exit(1); // free 해야함
	if(!_get_file(file_name, file_size, input_file))
		return (_free_input_file(input_file)); // free 해야함
	input_file[file_size] = '\0';
	printf("%s\n", input_file);
	inputs = ft_split(input_file, "\n");
	printf("Initial inputs\n");
	printf("%s\n", inputs[0]);
	printf("@@@@@@@@@@@@@@\n");
	free(input_file);
	_test_put_inputs(inputs); //test func
	input = (t_input *)malloc(sizeof(t_input) * 1);
	if (!input)
		return (_free_input_file(input_file)); // free
	_set_map_info(input, _read_line(inputs, 0, input->n));
	return (_set_map(input, inputs));
}

t_input	*_file_open(char *file_name, int is_stdin)
{
	if (is_stdin)
		return (_new_parser(0));
	else
		return (_new_parser(file_name));
}
