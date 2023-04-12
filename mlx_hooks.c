/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:56:51 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 12:15:04 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_hook_destroy(int key, t_mlx *mlx_data)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
		mlx_data->mlx_win = NULL;
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == 2)
		data->mlx_data->key_state.west = 1;
	if (key == 0)
		data->mlx_data->key_state.east = 1;
	if (key == 1)
		data->mlx_data->key_state.south = 1;
	if (key == 13)
		data->mlx_data->key_state.north = 1;
	if (key == 123)
		data->mlx_data->key_state.trigonometric_rotation = 1;
	if (key == 124)
		data->mlx_data->key_state.clockwise_rotation = 1;
	speed_control(key, data, 0);
	key_hook_destroy(key, data->mlx_data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 2)
		data->mlx_data->key_state.west = 0;
	if (key == 0)
		data->mlx_data->key_state.east = 0;
	if (key == 1)
		data->mlx_data->key_state.south = 0;
	if (key == 13)
		data->mlx_data->key_state.north = 0;
	if (key == 123)
		data->mlx_data->key_state.trigonometric_rotation = 0;
	if (key == 124)
		data->mlx_data->key_state.clockwise_rotation = 0;
	return (0);
}
