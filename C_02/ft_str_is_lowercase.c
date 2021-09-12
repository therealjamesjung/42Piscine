/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:20:30 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/12 17:20:57 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	index;
	int	flag;

	index = 0;
	flag = 1;
	while (str[index] != '\0')
	{
		if (str[index] < 'a' || str[index] > 'z')
			flag = 0;
		index++;
	}
	return (flag);
}
