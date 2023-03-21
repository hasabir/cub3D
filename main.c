/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/18 13:04:32 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		check_whitespace(data, &(data->other_whitespace), &tmp);
		if (ft_strcmp(*(data->line), "\n") && *tmp && !ft_isum(*tmp) && j < 7)
		{
			parse_texture(&data);
			data->textures[j++] = ft_strdup(*data->line);
		}
		else if (ft_strcmp(*(data->line), "\n")
			&& *tmp && ft_isum(*tmp) && !data->other_whitespace)
		{
			if (j != 6)
				ft_error("Number of textures not correct\n");
			data->textures[j] = NULL;
			break ;
		}
	}
}

void	ft_map(t_data *data)
{
	while (*(data->line))
	{
		data->init_map = ft_strjoin(data->init_map, *(data->line));
		free(*(data->line));
		*(data->line) = NULL;
		*(data->line) = get_next_line(data->fd);
		if (!*(data->line) || (*(data->line) && *(data->line)[0] == '\n'))
		{
			free (data->map);
			data->map = ft_split(data->init_map, '\n');
			parse_map(data->map);
			while (*(data->line) && *(data->line)[0] == '\n')
				*(data->line) = get_next_line(data->fd);
			break ;
		}
	}
	if (*(data->line))
	{
		free (*(data->line));
		ft_error("map_invalid\n");
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 2)
	{
		init_data(data, av);
		ft_textures(data);
		ft_map(data);
		close(data->fd);
		set_mlx_data(data);
		draw_map(data);
		mlx_loop_hook(data->mlx_data->mlx, loop_hook, data);
		mlx_loop(data->mlx_data->mlx);
		ft_free(data->textures);
		ft_free(data->map);
		ft_free(data->identifier);
		ft_free(data->tab_identifier);
	}
}
