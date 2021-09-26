/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:10:21 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/25 18:14:07 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
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
		return (NULL);
	while (index + min < max)
	{
		array[index] = index + min;
		index++;
	}
	return (array);
}
