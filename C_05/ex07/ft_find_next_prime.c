/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:50:17 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/24 23:08:01 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_sqrt(long long nb)
{
	long	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i < nb)
		++i;
	if (i * i == nb)
		return (i);
	return (0);
}

int	ft_is_prime(long long nb)
{
	long long	i;
	int sqrt;

	if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0)
		return (0);
	i = 2;
	sqrt = ft_sqrt(nb);
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	if (i > sqrt)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	long long	i;

	if (nb < 0)
		return (2);
	i = (long long) nb + 1;
	while (!ft_is_prime(i))
		i++;
	return (i);
}
