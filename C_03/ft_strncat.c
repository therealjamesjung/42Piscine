/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:41:53 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/15 20:28:05 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_init(char *src, unsigned int n)
{
	unsigned int	len;

	len = 0;
	while(*src)
	{
		src++;
		len++;
	}
	if (len >= n)
		return (1);
	else
		return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char	*start;

	if (!_init(src, n))
		return dest;
	i = 0;
	start = dest;
	while (*dest)
		dest++;
	dest = src;
	while (i++ < n && src[i] != '\0')
		src++;
	*(src) = '\0';
	
	return (start);
}
