/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:43:44 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/12 18:00:20 by jaekjung         ###   ########.fr       */
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
	if (c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
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

	index = 0;
	while (str[index + 1] != '\0')
	{
		if (index == 0 && _is_low(str[index]))
			_cap(&str[index]);
		else
		{
			if (_is_end(str[index]) == 1 && _is_low(str[index + 1]) == 1)
			{
				_cap(&str[index + 1]);
				index++;
			}
			else
				_low(&str[index]);
		}
		index++;
	}
	return (str);
}
