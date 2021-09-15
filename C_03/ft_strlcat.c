/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:49:49 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/15 21:32:53 by jaekjung         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int dest_len;
	char	*i_dest;
	char 	*i_src;

	i_dest = dest;
	i_src = src;
	while (size != 0 && *dest != '\0')
	{
		dest++;
		size--;
	}
		
	
	dest_len = dest - i_dest;
	i = 0;
	if (size == dest_len)
		return (dest_len + ft_strlen(src));
	while (i < size - 1 && *src !='\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (dest_len + (src - i_src));
}
