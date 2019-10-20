/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:53:05 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/18 15:53:12 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_cn(char *str, char c, int n);

/*
	dup until 'c' or \0.
	if n = -1, copy all string, else copy n chars.
*/
char	*ft_strdup_cn(char *str, char c, int n)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen_cn(str, c, n) + 1))))
		return(NULL);
	while (str && str[i] && str[i] != c && (((n > 0) && (i < n)) || (n < 0)))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* MAIN TEST*/
#include <stdio.h>
/*
int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("USAGE : ./ft_strcndup [str to dup] [stop char] [max len]\n");
		return (1);
	}
	else
	{
		char *str = ft_strdup_cn(argv[1], argv[2][0], atoi(argv[3]));
		printf("my printf : \"your string duped : [str]\"\n");
		printf("my call : ft_strdup_cn(argv[1], argv[2][0], atoi(argv[3]))\n");
		printf("your string duped : [%s]", str);
	}
	return (0);
}
*/
