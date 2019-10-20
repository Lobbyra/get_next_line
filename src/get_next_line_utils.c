/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:22:13 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/19 19:00:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strdup_cn(char *str, char c, int n)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen_cn(str, c, n) + 1))))
		return (NULL);
	while (str && str[i] && str[i] != c && (((n > 0) && (i < n)) || (n < 0)))
	{
		new[i] = str[i];
		i++;
	}
	if (n != -1)
		free(str);
	new[i] = '\0';
	return (new);
}

char	*ft_strcut_c(char *str, char c)
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
	if (!(new = (char*)malloc(sizeof(char) *
	(ft_strlen_cn(&str[i], '\0', -1) + 1))))
		return (NULL);
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*ft_strjoin_n(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (n == -1 && !(new = (char*)malloc(sizeof(char) *
	((ft_strlen_cn(s1, '\0', -1) + ft_strlen_cn(s2, '\0', -1) + 1)))))
		return (NULL);
	else if (!(new = (char*)malloc(sizeof(char) *
	((ft_strlen_cn(s1, '\0', -1) + ft_strlen_cn(s2, '\0', n) + 1)))))
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while ((n == -1 && s2[j]) || j < n)
		new[i++] = s2[j++];
	if (n != -1)
		free(s1);
	new[i] = '\0';
	return (new);
}
