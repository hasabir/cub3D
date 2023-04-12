/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:14:10 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 09:57:42 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate_player(t_data *data, int direction)
{
	if (direction == WEST)
		data->player.angle -= data->player.rotation_speed * (M_PI / 180);
	if (direction == EAST)
		data->player.angle += data->player.rotation_speed * (M_PI / 180);
}

void	move_up_down(t_data *data, int direction)
{
	long double	player_x;
	long double	player_y;

	player_x = data->coordinate.x1;
	player_y = data->coordinate.y1;
	player_x += (direction * data->player.speed * cos(data->player.angle));
	player_y += (direction * (-1)) * data->player.speed
		* sin(data->player.angle);
	move_u_d(data, player_x, player_y, direction);
}

void	move_west_east(t_data *data, int direction)
{
	double	player_x;
	double	player_y;

	player_x = data->coordinate.x1;
	player_y = data->coordinate.y1;
	player_x += direction * data->player.speed
		* cos(data->player.angle + M_PI / 2);
	player_y += (direction * (-1)) * data->player.speed
		* sin(data->player.angle + M_PI / 2);
	move_w_e(data, player_x, player_y, direction);
}

void	move_player(t_data *data, int type)
{
	if (type == SOUTH)
		move_up_down(data, -1);
	if (type == NORTH)
		move_up_down(data, 1);
	if (type == WEST)
		move_west_east(data, 1);
	if (type == EAST)
		move_west_east(data, -1);
}
