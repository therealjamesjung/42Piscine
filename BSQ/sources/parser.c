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
	
	ptr = 0;
	while (input_file[ptr] != '\n')
		ptr++;
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
	while (ptr >= 0)
	{
		n *= 10;
		n += input_file[ptr--] - '0';
	}
	input->n = n;
	if (input->n == 0)
		return (0); // map error
	return (1);

	// size = ft_strlen(line);
	// if (!line || size < 4)
	// 	return (0);
	// input->fill = line[size - 1];
	// input->obstacle = line[size - 2];
	// input->blank = line[size - 3];
	// if ((input->fill == input->obstacle) || \
	// 	(input->fill == input->blank) || \
	// 	(input->obstacle == input->blank))
	// 	return (0); // TODO 라인 ;;
	// line[size - 3] = '\0';
	// input->n = ft_atoi(line);
	// free(line);
	// if (input->n == 0)
	// 	return (0);
	// return (1);
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
	printf("%d line's len : %d\n", inx, i);
	if (i != len)
		return (0);
	else
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
	_test_put_inputs(input->map);
	return (1);
}

int	_get_file(char *file_name, char *input_file)
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
	read(fd, input_file, 2147483647);
	close(fd);
	return (1);
}

t_input	*_set_map(t_input *input, char *input_file)
{
	char	*ptr;

	ptr = input_file;
	// 이 아래 의심
	while (*ptr != '\n')
		ptr++;
	ptr++;
	//
	input->map = ft_split(ptr, "\n");
	free(input_file);
	if (_is_right_map(input))
		return (input);
	else
		return (0);
}

t_input	*_new_parser(char *file_name)
{
	char	*input_file;
	t_input	*input;

	input_file = (char *)malloc(sizeof(char) * (2147483647));
	if(!input_file)
		return (0);
	if(!_get_file(file_name, input_file))
		return(0); // file open fail. input_file free
	input = (t_input *)malloc(sizeof(t_input) * 1);
	if(!input)
		return (0); //null guard
	if (!_set_map_info(input, input_file)) // 0반환시 map error
		return (0);
	return (_set_map(input, input_file));
}

t_input	*_file_open(char *file_name, int is_stdin)
{
	if (is_stdin)
		return (_new_parser(0));
	else
		return (_new_parser(file_name));
}

