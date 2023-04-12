/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:25:28 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 11:04:49 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate(t_data *data)
{
	if (data->mlx_data->key_state.trigonometric_rotation)
		rotate_player(data, WEST);
	if (data->mlx_data->key_state.clockwise_rotation)
		rotate_player(data, EAST);
	if (data->mlx_data->key_state.m_trigonometric_rotation)
		rotate_player(data, WEST);
	if (data->mlx_data->key_state.m_clockwise_rotation)
		rotate_player(data, EAST);
}

void	move_hook(t_data *data)
{
	if (data->mlx_data->key_state.west || data->mlx_data->key_state.east
		|| data->mlx_data->key_state.south || data->mlx_data->key_state.north
		|| data->mlx_data->key_state.trigonometric_rotation
		|| data->mlx_data->key_state.clockwise_rotation
		|| data->mlx_data->key_state.m_clockwise_rotation
		|| data->mlx_data->key_state.m_trigonometric_rotation)
	{
		if (data->mlx_data->key_state.west)
			move_player(data, WEST);
		if (data->mlx_data->key_state.east)
			move_player(data, EAST);
		if (data->mlx_data->key_state.south)
			move_player(data, SOUTH);
		if (data->mlx_data->key_state.north)
			move_player(data, NORTH);
		rotate(data);
		mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->img->mlx_img);
		mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
		draw_map(data);
	}
}

void	speed_control(int key, t_data *data, int mouse_button)
{
	if (key == 69 && data->player.speed < 15)
		data->player.speed++;
	if (key == 78 && data->player.speed > 1)
		data->player.speed--;
	if ((key == 126 || mouse_button == 5)
		&& data->player.rotation_speed < 15)
		data->player.rotation_speed++;
	if ((key == 125 || mouse_button == 4)
		&& data->player.rotation_speed > 1)
		data->player.rotation_speed--;
}

int	destroy_window_x(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_key_state(t_data *data)
{
	data->mlx_data->key_state.north = 0;
	data->mlx_data->key_state.south = 0;
	data->mlx_data->key_state.east = 0;
	data->mlx_data->key_state.west = 0;
	data->mlx_data->key_state.clockwise_rotation = 0;
	data->mlx_data->key_state.trigonometric_rotation = 0;
	data->mlx_data->key_state.m_clockwise_rotation = 0;
	data->mlx_data->key_state.m_trigonometric_rotation = 0;
}
