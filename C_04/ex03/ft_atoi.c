/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:53:27 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/22 17:05:32 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	answer;
	int	is_positive;

	answer = 0;
	is_positive = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' \
		|| *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_positive *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		answer *= 10;
		answer += *str - '0';
		str++;
	}
	return (answer * is_positive);
}
