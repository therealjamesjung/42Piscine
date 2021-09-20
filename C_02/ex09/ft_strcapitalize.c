/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:43:44 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/20 15:07:49 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	_is_end(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (0);
	else if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

void	_cap(char *c)
{
	*c = *c - 'a' + 'A';
}

void	_low(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c - 'A' + 'a';
}

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	flag;

	index = 0;
	flag = 1;
	while (str[index] != '\0')
	{
		if (_is_end(str[index]))
		{
			flag = 1;
		}
		else if (flag)
		{
			if (_is_low(str[index]))
				_cap(&str[index]);
			flag = 0;
		}
		index++;
	}
	return (str);
}
