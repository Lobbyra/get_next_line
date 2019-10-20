/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlencn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:52:10 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/18 15:52:24 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	len until c || \0.
	- If n < 0, it not use this params.
	- Else return n if you know already the len.
	- Usefull if you have to manage strings which is sometimes
	non-null-terminated.
*/
int		ft_strlen_cn(char *str, char c, int n)
{
	int i;

	i = 0;
	if (n > 0)
		return (n);
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

/* MAIN TEST */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char **argv)
{
	if (argc != 4 && argv)
		printf("Usage : ./ft_strlencn [\"Your string\"] [stop char] [maxlen]");
	else
	{
		if ((strcmp(argv[1], "NULL") == 0))
			printf("%d\n", ft_strlencn(NULL, argv[2][0], atoi(argv[3])));
		printf("%d\n", ft_strlencn(argv[1], argv[2][0], atoi(argv[3])));
	}
	return (0);
}
*/
