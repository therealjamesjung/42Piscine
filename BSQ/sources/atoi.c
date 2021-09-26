/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:33:29 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/26 20:55:10 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\f' || c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}

int	is_operator(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	is_number(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	minus;

	result = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	while (is_operator(*str))
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * minus);
}
