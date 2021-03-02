/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:53:25 by nvu               #+#    #+#             */
/*   Updated: 2021/01/19 11:16:20 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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
