/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:10:21 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/28 10:30:03 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	index;

	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(int) * (max - min));
	if (range == NULL)
		return (0);
	index = 0;
	while (min < max)
		range[index++] = min++;
	return (range);
}
