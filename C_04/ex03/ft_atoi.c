/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:53:27 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/21 00:06:06 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_in_string(char c, char *str)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	_is_space(char c)
{
	if (_in_string(c, "\t\n\v\f\r "))
		return (1);
	return (0);
}
int	_is_operator(char c)
{
	if(_in_string(c, "+-"))
		return (1);
	return (0);
}

int	_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int	n;
	int	is_positive;

	n = 0;
	is_positive = 1;
	while (_is_space(*str))
		str++;
	while (_is_operator(*str))
	{
		if (*str == '-')
			is_positive *= -1;
		str++;
	}
	while (_is_number(*str))
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n * is_positive);
}