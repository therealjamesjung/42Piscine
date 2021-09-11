/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:12:09 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/11 14:34:11 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void ft_putchar(char *str)
{
    int index;

    index = 0;
    while (1)
    {
        if (str[index] == '\0')
        {
            write(1, str, 1);
        }
    }
}
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
