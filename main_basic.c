/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:42:58 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/30 07:56:28 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	char *trash;
	char *str;
	int ret;

	str = NULL;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &str)) && ret != -1)
	{
		printf("%s\n", str);
		free(str);
	}
	free(str);
	scanf("%sduigohf", trash);
	return (0);
}
