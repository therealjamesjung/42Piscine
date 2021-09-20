/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:18:46 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/20 19:39:21 by jaekjung         ###   ########.fr       */
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
	int				index;
	unsigned char	tmp;

	index = 0;
	while (1)
	{
		tmp = (unsigned char) str[index];
		if (tmp == '\0')
			break ;
		if (_is_prtble(tmp) == 1)
			ft_putchar(tmp);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[tmp / 16]);
			ft_putchar("0123456789abcdef"[tmp % 16]);
		}
		index++;
	}
}
