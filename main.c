/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 03:37:26 by Lobbyra           #+#    #+#             */
/*   Updated: 2019/10/30 08:15:27 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned int BOOL;

BOOL	stdin_reader(void)
{
	char	*str;
	int		ret;

	str = NULL;
	while ((ret = get_next_line(0, &str)) && ret > -1)
	{
		printf("[ret = %d]", ret);
		printf("%s\n", str);
		free(str);
	}
	printf("[ret = %d]", ret);
	if (str && str[0] == '\0')
		printf("[empty string]");
	else
		printf("%s\n", str);
	if (str != NULL)
		free(str);
	return (1);
}

BOOL	print_all_file(char *path)
{
	int		fd;
	int		ret;
	char	*str;

	fd = open(path, O_RDONLY);
	str = NULL;
	while ((ret = get_next_line(fd, &str)) && ret > -1)
	{
		printf("[ret = %d]", ret);
		printf("%s\n", str);
		free(str);
	}
	printf("[ret = %d]", ret);
	if (str && str[0] == '\0')
		printf("[empty string]");
	else
		printf("%s\n", str);
	if (str != NULL)
		free(str);
	return (1);
}

BOOL	print_n_line(char *path, int n)
{
	int		i;
	int		fd;
	int		ret;
	char	*str;

	i = 0;
	str = NULL;
	fd = open(path, O_RDONLY);
	while (i < n && (ret = get_next_line(fd, &str)) && ret > -1)
	{
		printf("[ret = %d]", ret);
		printf("%s\n", str);
		free(str);
		i++;
	}
	printf("[ret = %d]", ret);
	if (str && str[0] == '\0')
		printf("[empty string]");
	else
		printf("%s\n", str);
	if (str != NULL)
		free(str);
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
	str1 = NULL;
	str2 = NULL;
	str_stdin = NULL;
	while (
	(ret1 = get_next_line(fd1, &str1))			&&
	(ret2 = get_next_line(fd2, &str2))			&&
	(ret_stdin = get_next_line(0, &str_stdin)
	 && ret1 > -1 && ret2 > -1 && ret_stdin > -1)
		  )
	{
		if (ret1 > 0)
		{
			printf("[ret = %d]", ret1);
			printf("For  \"%s\" :\n[%s]\n\n", file1, str1);
			free(str1);
		}
		if (ret2 > 0)
		{
			printf("[ret = %d]", ret2);
			printf("For  \"%s\" :\n[%s]\n\n", file2, str2);
			free(str2);
		}
		if (ret_stdin > 0)
		{
			printf("[ret = %d]", ret_stdin);
			printf("For stdin :\n[%s]\n\n", str_stdin);
			free(str_stdin);
		}
	}
	printf("[ret1 = %d]", ret1);
	if (str1 && str1[0] == '\0')
		printf("[empty string]\n");
	else
		printf("%s\n", str1);
	printf("[ret2 = %d]", ret2);
	if (str2 && str2[0] == '\0')
		printf("[empty string]\n");
	else
		printf("%s\n", str2);
	printf("[ret_stdin = %d]", ret_stdin);
	if (str_stdin && str_stdin[0] == '\0')
		printf("[empty string]\n");
	else
		printf("%s\n", str_stdin);
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
	if (str_stdin != NULL)
		free(str_stdin);
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
			printf("[OK][RET = %d]\n", ret);
	}
	printf("\ntest with fd = 56 (not opened) :\nYour function must return -1 and do not touch at line...\n");
	printf("You can summon a infinity loop\n");

	ret = get_next_line(56, &str);
	if (str || ret != 1)
	{
		if (ret != -1)
			printf("[KO] Your function do not return -1 and it's wrong\n");
		else
			printf("[OK][RET = %d]\n", ret);
	}

	printf("\ntest with fd = -30 :\nYour function must return -1 and do not touch at line...\n");


	ret = get_next_line(-30, &str);
	if (str || ret != 1)
	{
		if (ret != -1)
			printf("Your function do not return -1 and it's wrong\n");
		else
			printf("[OK][RET = %d]\n", ret);
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
