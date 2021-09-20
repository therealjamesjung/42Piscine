/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:49:49 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/20 21:37:05 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

// Returns the full length of output string

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_len;
	unsigned int	src_len;

	index = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (index < size && *dest != '\0')
	{
		dest++;
		index++;
	}
	if (index == size)
		return (src_len + size);
	while (index < size - 1 && *src != '\0')
	{
		*dest = *src;
		index++;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_len + src_len);
}
