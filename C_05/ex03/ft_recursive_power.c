/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:30:44 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/21 00:57:21 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_power(int n, int power, int answer)
{
	if (power-- > 0)
		return (_power(n, power, answer *= n));
	return (answer);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (_power(nb, power, 1));
}
