/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:06:48 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/27 19:32:47 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup_str;

	dup_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup_str == NULL)
		return (0);
	i = -1;
	while (src[++i] != '\0')
		dup_str[i] = src[i];
	dup_str[i] = '\0';
	return (dup_str);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	t_stock_str	*array;

	if (!ac || !av)
		return (0);
	array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!array)
		return (0);
	index = 0;
	while (index < ac)
	{
		array[index].size = ft_strlen(av[index]);
		array[index].str = av[index];
		array[index].copy = ft_strdup(av[index]);
		index++;
	}
	array[index].str = 0;
	return (array);
}
