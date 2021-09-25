/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:19:10 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/25 18:16:36 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	index;
	long long	size;
	int			*array;

	index = 0;
	size = max - min;
	if (size <= 0)
		return (0);
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		return (-1);
	while (index + min < max)
	{
		array[index] = index + min;
		index++;
	}
	*range = array;
	return (size);
}
