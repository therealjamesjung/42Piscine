/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:17:58 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/24 01:14:17 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = -1;
	while (src[++index] != '\0')
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}


long long _calc_length(int size, char **strs, int sep_len)
{
	int			index;
	long long	res_length;

	index = -1;
	res_length = 0;
	while (++index < size)
	{
		res_length += ft_strlen(strs[index]);
		res_length += sep_len;
	}
	return (res_length - sep_len + 1);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	long long	result_len;
	long long	index;
	char		*result;
	char		*tmp;
	
	if (!size)
		return ((char *)malloc(sizeof(char)));
	result_len = _calc_length(size, strs, ft_strlen(sep));
	result = (char *)malloc(sizeof(char) * result_len);
	tmp = result;
	index = -1;
	while (++index < size)
	{
		ft_strcpy(tmp, strs[index]);
		tmp += ft_strlen(strs[index]);
		if (index < size - 1)
		{
			ft_strcpy(tmp, sep);
			tmp += ft_strlen(sep);
		}
	}
	*tmp = '\0';
	return (result);
}

#include <stdio.h>

int main()
{
	char **strs;
	char sep[10] = ", ";

	strs = (char **)malloc(sizeof(char *) * 3);

	for (int i=0; i<3; i++)
		strs[i] = (char *)malloc(sizeof(char) * 10);

	strs[0][0] = 'H';
	strs[0][1] = 'a';
	strs[0][2] = 'y';
	strs[1][0] = 'H';
	strs[1][1] = 'a';
	strs[1][2] = 'y';
	strs[2][0] = 'H';
	strs[2][1] = 'a';
	strs[2][2] = 'y';

	printf("%s\n", ft_strjoin(3, strs, sep));

	return 0;
}