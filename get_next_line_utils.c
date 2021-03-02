/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:04:56 by nvu               #+#    #+#             */
/*   Updated: 2021/02/03 09:47:19 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str && str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	while (i++ < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < len2)
		str[i + len1] = s2[i];
	str[i + len1] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		src_len;

	src_len = ft_strlen(src);
	ptr = malloc(sizeof(char) * src_len + 1);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < src_len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		ft_init(char **line, char *stock)
{
	int					i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
		{
			if (ft_sorting(line, stock))
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}
