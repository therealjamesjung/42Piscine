/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:52:27 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/25 14:51:31 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

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

long long	_calc_length(long long n, int to_base, int is_positive)
{
	long long	length;

	length = 0;
	while (1)
	{
		length++;
		if (n / to_base == 0)
			break ;
		n /= to_base;
	}
	if (!is_positive)
		length++;
	return (length);
}

long long	_get_base(char c, char *base)
{
	long long	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*_to_base(char *base, long long n, int to_base)
{
	int		index;
	int		length;
	int		is_positive;
	char	*result;

	is_positive = (n > 0);
	length = _calc_length(n, to_base, is_positive);
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	index = 0;
	if (!is_positive)
	{
		result[0] = '-';
		index = 1;
		n *= -1;
	}
	while (index < length)
	{
		result[length - is_positive - index++] = base[n % to_base];
		n /= to_base;
	}
	result[length] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			from_base;
	int			is_positive;
	long long	result;

	if (!_validate_base(base_from) || !_validate_base(base_to))
		return (NULL);
	from_base = ft_strlen(base_from);
	result = 0;
	is_positive = 1;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
		if (*(nbr++) == '-')
			is_positive *= -1;
	while (_get_base(*nbr, base_from) != -1)
	{
		result *= from_base;
		result += _get_base(*nbr, base_from);
		nbr++;
	}
	return (_to_base(base_to, result * is_positive, ft_strlen(base_to)));
}
