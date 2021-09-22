/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:52:53 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/22 11:48:57 by jaekjung         ###   ########.fr       */
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

int	_check(char *str, char *to_find)
{
	int	index;

	index = 0;
	while (to_find[index] != '\0')
	{
		if (str[index] != to_find[index])
			return (0);
		index++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (ft_strlen(str) < ft_strlen(to_find))
		return (0);
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
			if (_check(str, to_find))
				return (str);
		str++;
	}
	return (0);
}
