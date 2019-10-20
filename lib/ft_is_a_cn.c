/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_cn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:29:12 by Lobbyra           #+#    #+#             */
/*   Updated: 2019/10/19 09:29:15 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	is_a_cn return 1 if found c in n chars.
	If n == -1, this function do not care of this params.

*/

int		ft_is_a_cn(char *str, char c, int n)
{
	int i;

	i = 0;
	while (str && str[i] && ((n > 0 && i < n) || n < 0))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}

/* MAIN TEST */

/*
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("USAGE : ./ft_is_a_cn [str] [char to find] [n chars to check]\n");
		return (1);
	}
	else
	{
		printf("ft_is_a_cn return : %d", ft_is_a_cn(argv[1], argv[2][0], atoi(argv[3])));
		return (0);
	}
	return (0);
}
*/
