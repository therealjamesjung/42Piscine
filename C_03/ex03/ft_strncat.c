/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:41:53 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/20 16:48:32 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*p;

	p = dest;
	while (*p != '\0')
		p++;
	while (*src != '\0' && nb > 0)
	{
		*p = *src;
		p++;
		src++;
		nb--;
	}
	*p = '\0';
	return (dest);
}
