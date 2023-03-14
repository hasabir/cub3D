/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/14 12:34:58 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char **fill_TabIdentifier()
{
	char **identifier;

	identifier = malloc(sizeof(char *) * 7);
	if (!identifier)
		return (NULL);
	identifier[0] = ft_strdup("NO");
	identifier[1] = ft_strdup("SO");
	identifier[2] = ft_strdup("WE");
	identifier[3] = ft_strdup("EA");
	identifier[4] = ft_strdup("F");
	identifier[5] = ft_strdup("C");
	identifier[6] = NULL;
	return (identifier);
}

// void	ft_free(char **map)
// {
// 	while (map && *map)
// 	{
// 		free (*map);
// 		*map = NULL;
// 	}
// }

void	init_data(t_data *data, char **av)
{
	(data->line) = malloc(sizeof(char *));
	if (!data->line)
		exit(1);
	*(data)->line = ft_strdup("");
	(data)->tab_identifier = NULL;
	(data)->identifier = fill_TabIdentifier();
	(data)->init_map = ft_strdup("");
	(data)->map = malloc(sizeof(char *));
	if (!data->map)
		exit(1);
	(data)->textures = malloc(sizeof(char *));
	(data)->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		exit(1) ;
}


void	ft_textures(t_data *data)
{
	char	*tmp;
	int		other_whitespace;
	int		j;

	j = 0;
	while (*(data->line))
	{
		free(*data->line);
		other_whitespace = 0;
		(*data->line) = get_next_line(data->fd);
		check_whitespace(data, &other_whitespace, &tmp);
		if (ft_strcmp(*(data->line), "\n") && *tmp && !ft_isum(*tmp))
		{
			parse_texture(&data);
			data->textures[j++] = ft_strdup(*data->line);
		}
		else if (ft_strcmp(*(data->line), "\n")
			&& *tmp && ft_isum(*tmp) && !other_whitespace)
		{
			data->textures[j] = NULL;
			break ;
		}
	}
	if (len_tab(data->textures) != 6)
		ft_error("Number of textures not correct\n");
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

// void	ft_free_data(data)
// {
	
// }

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
	}
	// ft_free_data(data);
}
