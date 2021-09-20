/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:18:46 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/15 12:59:10 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	_is_prtble(char c)
{
	if (c < 32 || c > 127)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (_is_prtble(str[index]) == 1)
			ft_putchar(str[index]);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[index] / 16]);
			ft_putchar("0123456789abcdef"[str[index] % 16]);
		}
		index++;
	}
}
