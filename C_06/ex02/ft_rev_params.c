/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:03:52 by jaekjung          #+#    #+#             */
/*   Updated: 2021/09/21 01:28:28 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		write(1, &str[index++], 1);
}

int	main(int argc, char **argv)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		ft_putstr(argv[argc - 1 - index++]);
		ft_putstr("\n");
	}
}
