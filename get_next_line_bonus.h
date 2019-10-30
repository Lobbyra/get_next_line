/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 09:42:57 by jecaudal          #+#    #+#             */
/*   Updated: 2019/10/30 09:43:11 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define GNL_LINE_READED 1
# define GNL_EOF 0
# define GNL_ERROR -1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

int		ft_strlen_c(char *str, char c);
char	*ft_strjoin(char *s1, char *s);
char	*ft_strcut_c(char *post_buffer, char c);
char	*ft_strdup_c(char *str, char c);
int		is_a_c(char *str, char c);
int		get_next_line(int fd, char **line);

#endif
