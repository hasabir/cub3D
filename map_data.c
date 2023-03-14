/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:41:39 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/14 08:40:06 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int get_size_x(char **map)
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
	int i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

void get_player_position(t_data *data)
{
	int pos;
	
	pos = 0;
	data->player.player_y = -1;
	while (data->map[++(data->player.player_y)])
	{
		data->player.player_x = -1;
		while (data->map[data->player.player_y][++data->player.player_x])
		{
			if (data->map[data->player.player_y][data->player.player_x] == 'N')
			{
				pos = 1;
				break;
			}
		}
		if (pos)
			break;
	}
	data->player.player_x = 30 * data->player.player_x + 10;
	data->player.player_y = 30 * data->player.player_y + 10;
}