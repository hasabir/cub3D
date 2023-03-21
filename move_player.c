/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:14:10 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/21 22:07:32 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	can_move(t_data *data, double *player_x, double *player_y)
{
	if (data->map[(int)(*player_y / 30)][(int)(*player_x / 30)] == '1')
	{
		return (0);
	}
	return (1);
}

void	rotate_player(t_data *data, int direction)
{
	if (direction == WEST)
		data->player.angle += M_PI / 12;
	if (direction == EAST)
		data->player.angle -= M_PI / 12;
}

void	move_up_down(t_data *data, int direction)
{
	double	player_x;
	double	player_y;
	int		limit_x;
	int		limit_y;
	double		tmp_x;
	double		tmp_y;

	player_x = data->coordinate.x1;
	player_y = data->coordinate.y1;
	player_x += (direction * data->player.speed * cos(data->player.angle));
	player_y += (direction * (-1)) * data->player.speed
		* sin(data->player.angle);
	if (!can_move(data, &player_x, &player_y))
	{
		printf("\033[91mI told you !\n\033[00m");
		return ;
	}
	
	limit_x = (int)(player_x / 30);
	limit_y = (int)(player_y / 30);
	
	
	tmp_x = player_x + (direction * data->player.speed * cos(data->player.angle));
	tmp_y = player_y + (direction * (-1)) * data->player.speed
		* sin(data->player.angle);
	if (!can_move(data, &tmp_x, &tmp_y))
		printf("I won't move\n");
	data->coordinate.x1 = player_x;
	data->coordinate.y1 = player_y;
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
	if (!can_move(data, &player_x, &player_y))
		return ;
	data->coordinate.x1 = player_x;
	data->coordinate.y1 = player_y;
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
