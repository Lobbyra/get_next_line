/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:52:44 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/18 15:53:15 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

/*
	ft_strcut_c		- take c which as separator, it's all chars before it
					what will be saved.

	Example of uses : 
			1. 	"i want to take\n the first line\n of this\n string" "\n"
	  return :	"i want to take"

*/

char		*ft_strcut_c(char *str, char c)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(str))
		return (NULL);
	if (ft_is_a_cn(str, c, -1) == 0)
		return (NULL);
	while (str[i] != c)
		i++;
	i++;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen_cn(&str[i], '\0', -1) + 1))))
		return (NULL);
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

/* MAIN TEST */
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("USAGE : ./ft_strcut_c[string to clean] [char separator]\n");
		return (1);
	}
	else
	{
		char *str = ft_strcut_c(argv[1], argv[2][0]);
		printf("my printf : [str]\n");
		printf("Your string cuted : [%s]\n", str);
		free(str);
	}
	return (0);
}
