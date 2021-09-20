/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:04:51 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/20 14:48:50 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (src[index] != '\0' && index + 1 < size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ft_strlen(src));
}

#include <stdio.h>
#include <string.h>
int main()
{
	char s1[100] = "Asdf AA";
	char s2[100] = "kkkkk";

	printf("%u\n", ft_strlcpy(s1, s2, 8));
	printf("%s", s1);

	return 0;
}