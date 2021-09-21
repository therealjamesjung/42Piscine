/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:13:31 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/22 01:34:31 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int	_validate_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] == '\n' || base[i] == '\t' || \
			base[i] == '\v' || base[i] == '\r')
			return (0);
	}
	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (base[++j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int	_get_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_n;
	int	answer;
	int	is_positive;

	if (!_validate_base(base))
		return (0);
	base_n = ft_strlen(base);
	is_positive = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_positive *= -1;
		str++;
	}
	answer = 0;
	while (_get_base(*str, base) != -1)
	{
		answer *= base_n;
		answer += _get_base(*str, base);
		str++;
	}
	return (answer * is_positive);
}
