/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:37:05 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/19 18:58:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define GNL_LINE_READED 1
# define GNL_EOF 0
# define GNL_ERROR -1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

void	ft_bzero(void *s, size_t n);
int		ft_strlen_cn(char *str, char c, int n);
char	*ft_strjoin_n(char *s1, char *s2, int n);
char	*ft_strcut_c(char *post_buffer, char c);
char	*ft_strdup_cn(char *str, char c, int n);
int		ft_is_a_cn(char *str, char c, int n);
int		get_next_line(int fd, char **line);

#endif
