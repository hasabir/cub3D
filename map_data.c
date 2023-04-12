/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:41:39 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 11:18:51 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_size_x(char **map)
{
	int	stock;
	int	i;
	int	j;

	i = -1;
	stock = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			;
		if (stock < j)
			stock = j;
	}
	return (stock);
}

int	get_size_y(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

void	get_player_position(t_data *data)
{
	int	x;
	int	y;

	data->player.direction = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'N' ||
				data->map[y][x] == 'S' ||
				data->map[y][x] == 'W' ||
				data->map[y][x] == 'E')
			{
				data->player.direction = data->map[y][x];
				break ;
			}
		}
		if (data->player.direction)
			break ;
	}
	data->player.player_y = 50 * y + 25;
	data->player.player_x = 50 * x + 25;
}
