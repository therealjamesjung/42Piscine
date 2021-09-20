/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:43:44 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/20 19:38:52 by jaekjung         ###   ########.fr       */
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
	if (_is_low(*c))
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
			flag = 1;
		else
		{
			if (flag)
			{
				_cap(&str[index]);
				flag = 0;
			}
			else
				_low(&str[index]);
		}
		index++;
	}
	return (str);
}
