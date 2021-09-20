/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:18:02 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/21 00:27:19 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_factorial(int result, int n)
{
	if (n == 1)
		return (result);
	return (_factorial(result * n, n - 1));
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		return (_factorial(1, nb));
}
