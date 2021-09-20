/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:28:12 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/21 00:58:00 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	answer = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		answer *= nb;
		power--;
	}
	return (answer);
}
