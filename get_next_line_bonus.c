/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:48:42 by nvu               #+#    #+#             */
/*   Updated: 2021/02/03 09:48:47 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_stocking(char *line, char *stock, int i)
{
	int					j;

	j = i + 1;
	while (line[++i] != '\0')
		stock[i - j] = line[i];
	stock[i - j] = '\0';
	return (0);
}

int	ft_sorting(char **line, char *stock)
{
	int					i;
	char				*temp;

	i = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
	{
		if (ft_stocking((*line), stock, i))
			return (1);
		if (!(temp = malloc(sizeof(char) * (i + 1))))
			return (1);
		i = -1;
		while ((*line)[++i] != '\n')
			temp[i] = (*line)[i];
		temp[i] = '\0';
		free(*line);
		(*line) = temp;
	}
	else
		stock[0] = '\0';
	return (0);
}

int	ft_readoneline(int fd, char *buf, char **line, char *stock)
{
	int					i;
	int					out;

	while ((out = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[out] = '\0';
		if (!((*line) = ft_strjoin((*line), buf)))
			return (-1);
		if (out == 0 || out < BUFFER_SIZE)
			break ;
		i = 0;
		while (buf[i] != '\0' && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			break ;
	}
	if (out >= 0)
		if (ft_sorting(line, stock))
			return (-1);
	return (out);
}

int	ft_reading(int fd, char **line, char *stock)
{
	char				buf[BUFFER_SIZE + 1];
	int					out;
	int					one;
	int					i;

	if (!((*line) = ft_strdup(stock)))
		return (-1);
	out = ft_init(line, stock);
	if (out == -1 || out == 1)
		return (out);
	out = ft_readoneline(fd, buf, line, stock);
	if (out == -1)
		return (-1);
	one = 0;
	i = -1;
	while (buf[++i] != '\0')
		if (buf[i] == '\n')
			one = 1;
	if ((out == 0 || out < BUFFER_SIZE) && stock[0] == '\0' && one == 0)
		out = 0;
	else
		out = 1;
	return (out);
}

int	get_next_line(int fd, char **line)
{
	static char			stock[BUFFER_SIZE + 1] = {0};
	int					out;

	if (fd < 0 || !line || read(fd, stock, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	out = ft_reading(fd, line, stock);
	if (out == -1)
	{
		if (*line)
			free(*line);
	}
	return (out);
}
