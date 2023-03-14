/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:48:46 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/14 12:31:26 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	char	*p2;

	p = (char *)malloc(ft_strlen(src) + 1);
	if (!p)
		return (NULL);
	p2 = p;
	while (src && *src)
		*p++ = *src++;
	*p = '\0';
	return (p2);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*stock;
	char	*pstock;
	char	*pline;

	if (!(*line))
	{
		free(line);
		return (ft_strdup(buff));
	}
	stock = malloc(ft_strlen(line) + ft_strlen(buff) + 1);
	if (!stock)
		return (NULL);
	pstock = stock;
	pline = line;
	while (*line)
		*stock++ = *line++;
	while (*buff)
		*stock++ = *buff++;
	*stock = '\0';
	free(pline);
	return (pstock);
}

int	is_whitespace(char c)
{
	if (c == 9 || (c > 10 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	check_whitespace(t_data *data, int *other_whitespace, char **tmp)
{
	*tmp = (*data->line);
	if (data->line && *(data->line) && is_whitespace(**(data->line)))
	{
		while (is_whitespace(**tmp))
		{
			if (**tmp != ' ')
				other_whitespace++;
			(*tmp)++;
		}
		if (*(*tmp)++ == '\n')
			other_whitespace = 0;
	}
}