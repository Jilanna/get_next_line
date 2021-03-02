/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:48:58 by nvu               #+#    #+#             */
/*   Updated: 2021/02/03 09:49:00 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *src);
int			ft_double(char **line, char *stock, int i);
int			ft_init(char **line, char *stock);
int			ft_sorting(char **line, char *stock);
int			ft_stocking(char *line, char *stock, int i);
int			ft_readoneline(int fd, char *buf, char **line, char *stock);
int			ft_reading(int fd, char **line, char *stock);
int			get_next_line(int fd, char **line);

#endif
