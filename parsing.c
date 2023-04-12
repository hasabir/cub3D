/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:42:35 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/11 09:42:36 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_end(char **map, int *i)
{
	int	j;

	j = 0;
	while (map[++(*i)])
	{
		j = 0;
		while (map[*i][j] && is_whitespace(map[*i][j]))
				j++;
		if (map[*i][j] && map[*i][j] != '\n')
			ft_error("ERROR\n");
	}
}

int	ft_end_stock_textures(t_data *data, char *tmp, int *j)
{
	if (ft_strcmp(*(data->line), "\n")
		&& *tmp && ft_isum(*tmp) && !data->other_whitespace)
	{
		if (*j != 6)
			ft_error("ERROR\n");
		data->textures[*j] = NULL;
		return (1);
	}
	return (0);
}

void	ft_textures(t_data *data)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = NULL;
	while (*(data->line))
	{
		free(*data->line);
		data->other_whitespace = 0;
		(*data->line) = get_next_line(data->fd);
		if (!*data->line)
			ft_error("ERROR\n");
		check_whitespace(data, &tmp);
		if (ft_strcmp(*(data->line), "\n") && *tmp && !ft_isum(*tmp) && j < 7)
		{
			parse_texture(&data);
			data->textures[j++] = ft_strdup(*data->line);
		}
		else if (ft_end_stock_textures(data, tmp, &j))
			break ;
	}
}

void	ft_map(t_data *data)
{
	while (*(data->line))
	{
		data->init_map = ft_strjoin(data->init_map, *(data->line));
		free(*(data->line));
		*(data->line) = get_next_line(data->fd);
		if (!*(data->line) || (*(data->line) && *(data->line)[0] == '\n'))
		{
			free (data->map);
			data->map = ft_split(data->init_map, '\n');
			parse_map(data->map);
			while (*(data->line) && *(data->line)[0] == '\n')
			{
				free(*(data->line));
				*(data->line) = get_next_line(data->fd);
			}
			while (check_end_map(data))
			{
				free(*(data->line));
				*(data->line) = get_next_line(data->fd);
			}
			break ;
		}
	}
}
