/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_wtf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:10:21 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/28 10:30:52 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	index;
	int	*array;

	index = 0;
	if (max - min <= 0)
		return (0);
	array = (int *)malloc(sizeof(int) * (max - min));
	if (array == NULL)
		return (0);
	while (index < (max - min))
	{
		array[index] = index + min;
		index++;
	}
	return (array);
}