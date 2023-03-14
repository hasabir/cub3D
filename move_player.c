/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:14:10 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/14 15:22:23 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	canMove(t_data *data)
{
	if (data->map[data->player.player_y / 30][data->player.player_x / 30] == '1')
		return (0);
	return (1);
}

void move_player(t_data *data, int type)
{
	if (type == BACK)
	{
		data->player.player_y += 10;
		if (!canMove(data))
			data->player.player_y -= 10;
	}
	if (type == FORWARD)
	{
		data->player.player_y -= 10;
		if (!canMove(data))
			data->player.player_y += 10;
	}
	if (type == RIGHT)
	{
		data->player.player_x += 10;
		if (!canMove(data))
			data->player.player_x -= 10;
	}
	if (type == LEFT)
	{
		data->player.player_x -= 10;
		if (!canMove(data))
			data->player.player_x += 10;
	}
	return ;
}

