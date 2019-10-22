/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 09:04:57 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/22 16:34:01 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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

int		get_next_line_reading(int fd, char **post_buffer, char **line)
{
	int			ret_read;
	char		buf[BUFFER_SIZE];

	while ((ret_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret_read == -1)
			break ;
		if (ft_is_a_cn(buf, '\n', ret_read) == 1)
		{
			*post_buffer = ft_strjoin_n(*post_buffer, buf, ret_read);
			break ;
		}
		*post_buffer = ft_strjoin_n(*post_buffer, buf, ret_read);
	}
	if (ret_read >= 0 && ft_is_a_cn(*post_buffer, '\n', -1) == 1)
	{
		*line = ft_strdup_cn(*post_buffer, '\n', -1);
		*post_buffer = ft_strcut_c(*post_buffer, '\n');
		return (GNL_LINE_READED);
	}
	if (ret_read == 0)
		return (GNL_EOF);
	return (GNL_ERROR);
}

int		get_next_line(int fd, char **line)
{
	static char	*post_buffer[255];

	if (fd >= 0 && !(post_buffer[fd]))
	{
		if (!(post_buffer[fd] = (char*)malloc(1)))
			return (0);
		post_buffer[fd][0] = '\0';
	}
	if (fd >= 0 && ft_is_a_cn(post_buffer[fd], '\n', -1) == 1)
	{
		*line = ft_strdup_cn(post_buffer[fd], '\n', -1);
		post_buffer[fd] = ft_strcut_c(post_buffer[fd], '\n');
		return (GNL_LINE_READED);
	}
	if (fd >= 0)
		return (get_next_line_reading(fd, &post_buffer[fd], line));
	return (GNL_ERROR);
}
