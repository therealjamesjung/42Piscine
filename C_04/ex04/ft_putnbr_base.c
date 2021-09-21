/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:40:32 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/21 16:34:22 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	_print_base(int n, char *base, int base_n)
{
	if (n >= base_n)
		_print_base(n / base_n, base, base_n);
	write(1, &base[n % base_n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!_validate_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	_print_base(nbr, base, ft_strlen(base));
}
