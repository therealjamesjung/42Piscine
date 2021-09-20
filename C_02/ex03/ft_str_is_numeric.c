/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:15:09 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/12 17:19:29 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	index;
	int	flag;

	index = 0;
	flag = 1;
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			flag = 0;
		index++;
	}
	return (flag);
}
