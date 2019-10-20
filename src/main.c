/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 03:37:26 by Lobbyra           #+#    #+#             */
/*   Updated: 2019/10/20 03:37:33 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str;
		int ret;
		int fd;

		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &str)))
			printf("%s\n", str);
	}
	else if (argc == 3)
	{
		char *str;
		char *str2;
		char *str_stdin;
		int ret;
		int ret2;
		int ret_stdin;
		int fd;
		int fd2;

		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while ((ret = get_next_line(fd, &str))
		&& (ret2 = get_next_line(fd2, &str2))
		&& (ret_stdin = get_next_line(0, &str_stdin)))
		{
			if (ret)
				printf("file 1 = \n[%s]\n\n", str);
			if (ret2)
				printf("file 2 = \n[%s]\n\n", str2);
			if (ret_stdin)
				printf("stdin = \n[%s]\n\n", str_stdin);
		}
	}
	else
		printf("wrong usage\n");
	return (0);
}
