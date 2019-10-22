/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 03:37:26 by Lobbyra           #+#    #+#             */
/*   Updated: 2019/10/22 17:26:54 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <string.h>
#include <stdlib.h>

typedef unsigned int BOOL;

BOOL	stdin_reader(void)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		printf("%s\n", str);
		free(str);
	}
	return (1);
}

BOOL	print_all_file(char *path)
{
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		printf("%s\n", str);
		free(str);
	}
	return (1);
}

BOOL	print_n_line(char *path, int n)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(path, O_RDONLY);
	while (i < n && get_next_line(fd, &str))
	{
		printf("%s\n", str);
		free(str);
		i++;
	}
	return (1);
}

BOOL	print_multi_fd(char *file1, char *file2)
{
	int		fd1;
	int		fd2;
	int		ret1;
	int		ret2;
	int		ret_stdin;
	char	*str1;
	char	*str2;
	char	*str_stdin;

	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	while (
	(ret1 = get_next_line(fd1, &str1))			&&
	(ret2 = get_next_line(fd2, &str2))			&&
	(ret_stdin = get_next_line(0, &str_stdin))
		  )
	{
		if (ret1 > 0)
		{
			printf("For  \"%s\" :\n[%s]\n\n", file1, str1);
			free(str1);
		}
		if (ret2 > 0)
		{
			printf("For  \"%s\" :\n[%s]\n\n", file2, str2);
			free(str2);
		}
		if (ret_stdin > 0)
		{
			printf("For stdin :\n[%s]\n\n", str_stdin);
			free(str_stdin);
		}
	}
	return (1);
}

void	error_management()
{
	/*
		Error actually tested :
			- Wrong file descriptor.
	*/
	printf("Welcome to the error management test center :\n");
	printf("--------------------------------------------------------\n");
	printf("We will now test your file descriptor error management :\n\n");
	printf("test with fd = -1 :\nYour function must return -1 and do not touch at line...\n");

	char	*str;
	int		ret;

	ret = get_next_line(-1, &str);
	if (str || ret != 1)
	{
		if (ret != -1)
			printf("Your function do not return -1 and it's wrong\n");
		else
			printf("[OK]\n");
	}
	printf("\ntest with fd = 56 (not opened) :\nYour function must return -1 and do not touch at line...\n");
	printf("You can summon a infinity loop\n");

	ret = get_next_line(56, &str);
	if (str || ret != 1)
	{
		if (ret != -1)
			printf("[KO] Your function do not return -1 and it's wrong\n");
		else
			printf("[OK]\n");
	}

	printf("\ntest with fd = -30 :\nYour function must return -1 and do not touch at line...\n");


	ret = get_next_line(-30, &str);
	if (str || ret != 1)
	{
		if (ret != -1)
			printf("Your function do not return -1 and it's wrong\n");
		else
			printf("[OK]\n");
	}
	printf("--------------------------------------------------------\n");
	printf("It's a pause to check if this fun produce a leak.\nIt's to check if line is modified by the fun tested.\n\nPress return to quit...");
	scanf("coucou");
	printf("\nThe error mangement close his door, thank you for coming.\n");
	printf("Bye...\n");
}

void	help(void)
{
	printf("./get_next_line -> fd = stdin;\n");
	printf("./get_next_line [file1] -> print your file line by line until EOF\n");
	printf("./get_next_line [file1] [file2] -> multi fd (open(argv[1]) && open(argv[2]) && stdin)\n");
	printf("./get_next_line -n [file] [n-line to print] -> print n-line from a file\n");
	printf("./get_next_line --error -> It will do some tests about how get_next_line manage and how it may manage error cases");

	printf("If you want to check memory leaks, add -ml at in first arg\n");
}

void	gnl_leaks(int argc, char **argv)
{
	BOOL state = 0;
	if (argc == 2)
		state = stdin_reader();
	else if (argc == 3)
		state = print_all_file(argv[2]);
	else if (argc == 4)
		state = print_multi_fd(argv[2], argv[3]);
	else if (argc == 5 && strcmp(argv[2], "-n") == 0)
		state = print_n_line(argv[4], atoi(argv[3]));
	if (state == 1)
	{
		printf("It's a pause to check if this fun produce a leak.\n\n");
		scanf("coucou");
	}
}

void	gnl_test(int argc, char **argv)
{
	if (argc == 2)
		print_all_file(argv[1]);
	else if (argc == 3)
		print_multi_fd(argv[1], argv[2]);
	else if (argc == 4 && strcmp(argv[1], "-n") == 0)
		print_n_line(argv[3], atoi(argv[2]));
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		stdin_reader();
	else if (strcmp(argv[1], "--help") == 0)
		help();
	else if (strcmp(argv[1], "--error") == 0)
		error_management();
	else if (strcmp(argv[1], "-ml") == 0)
		gnl_leaks(argc, argv);
	else
		gnl_test(argc, argv);
	return (0);
}
