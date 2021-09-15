/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:03:59 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/15 20:06:10 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] || i < n)
	{
		if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return (s2[i] - s1[i]);
}
