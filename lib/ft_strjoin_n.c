/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:52:33 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/19 19:04:38 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Create a new string what s1 and s2 fit in there. copy s1 in this new string
	and concatenate s2 at the end of s1.
	If n < 0, copy all s2, else copy n char of s2 at the end of s1 in the new
	string.
	if s1 == NULL return strdup(s2), if s2 == NULL return strdup(s1)
	else if s1 and s2 == NULL return NULL,
*/

#include "../get_next_line.h"

char	*ft_strjoin_n(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1))
		return (ft_strdup_cn(s2, '\0', -1));
	else if (!(s2))
		return (ft_strdup_cn(s1, '\0', -1));
	if (n == -1 && !(new = (char*)malloc(sizeof(char) *
	((ft_strlen_cn(s1, '\0', -1) + ft_strlen_cn(s2, '\0', -1) + 1)))))
		return(NULL);
	else if (!(new = (char*)malloc(sizeof(char) *
	((ft_strlen_cn(s1, '\0', -1) + ft_strlen_cn(s2, '\0', n) + 1)))))
		return(NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while ((n == -1 && s2[j]) || j < n)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

/* MAIN TEST */

 #include <stdio.h>
 #include <stdlib.h>

 int		main(int argc, char **argv)
 {
 	if (argc != 4)
 		printf("USAGE : ./ft_strjoin_n [s1] [s2] [n]\n");
 	else
 	{
 		char *str = ft_strjoin_n(argv[1], argv[2], atoi(argv[3]));
 		printf("strs joined = [%s]\n", str);
 		free(str);
 	}
 	return (0);
 }
