/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:22:25 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/12 17:22:51 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	index;
	int	flag;

	index = 0;
	flag = 1;
	while (str[index] != '\0')
	{
		if (str[index] < 'A' || str[index] > 'Z')
			flag = 0;
		index++;
	}
	return (flag);
}
