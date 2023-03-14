/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:43:41 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/23 18:58:15 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_search(char *line)
{
	int	position;

	position = 0;
	if (!line)
		return (0);
	while (*line)
	{
		position++;
		if (*line == '\n')
			return (position);
		line++;
	}
	return (0);
}

char	*ft_line(char *save, int position, int n)
{
	char	*line;
	int		i;

	i = -1;
	if (!*save)
		return (NULL);
	if (n == 0)
		position = ft_strlen(save);
	line = malloc(position + 1);
	if (!line)
		return (NULL);
	while (++i < position)
		line[i] = save[i];
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *save, int n)
{
	char	*str;
	char	*pstr;
	int		position;
	char	*saveplus;

	if (n == 0)
		return (NULL);
	n = 1;
	position = ft_search(save);
	saveplus = save + position;
	str = malloc(ft_strlen(saveplus) + 1);
	if (!str)
		return (NULL);
	pstr = str;
	while (*saveplus)
		*str++ = *saveplus++;
	*str = '\0';
	return (pstr);
}

char	*ft_get_line(char *line, char **save, int n)
{
	char	*tmp;

	tmp = ft_line(line, ft_search(line), n);
	*save = ft_save(line, n);
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*save[OPEN_MAX];
	int			n;

	if (fd < 0|| read (fd, NULL, 0) < 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup ("");
	line = ft_strdup(save[fd]);
	free(save[fd]);
	save[fd] = NULL;
	buff = malloc(2);
	if (!buff)
		return (NULL);
	n = 1;
	while (n && ft_search(line) == 0)
	{
		n = read(fd, buff, 1);
		*(buff + n) = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (ft_get_line(line, &save[fd], n));
}
