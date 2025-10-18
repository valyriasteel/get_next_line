/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:22:48 by bbosnak           #+#    #+#             */
/*   Updated: 2023/07/27 11:22:49 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_merge_data(char *save, char *s2, int i, int j)
{
	char	*str;

	if (!save)
	{
		str = malloc(sizeof(char) * ft_strlen(s2) + 1);
		if (!str)
			return (NULL);
		while (s2[++i])
			str[i] = s2[i];
	}
	else
	{
		str = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(s2)) + 1);
		if (!str || !save || !s2)
			return (NULL);
		while (save[++i])
			str[i] = save[i];
		while (s2[++j])
			str[i++] = s2[j];
	}
	str[i] = 0;
	free(save);
	return (str);
}

static char	*ft_read_data(int fd, char *save)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (ft_notnewline(save) && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1 || (!save && i == 0))
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		save = ft_merge_data(save, str, -1, -1);
		if (!save)
			return (NULL);
	}
	free (str);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[4096];
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = ft_read_data(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	len = ft_linelen(save[fd]);
	line = ft_strndup(save[fd], len);
	save[fd] = save_rest(save[fd], len);
	return (line);
}
