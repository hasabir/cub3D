/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:56:51 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/27 10:13:58 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	destroy_window_x(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

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

// int key_hook(int key, t_data *data)
// {
// 	data->mlx_data->key_state[key] = 1;
// 	key_hook_destroy(key, data->mlx_data);
// 	return (0);
// }

// int key_release(int key, t_data *data)
// {
// 	data->mlx_data->key_state[key] = 0;
// 	return (0);
// }

// int	move_hook(t_data *data)
// {
// 	if (data->mlx_data->key_state[0] || data->mlx_data->key_state[2]
// 		|| data->mlx_data->key_state[1] || data->mlx_data->key_state[13]
// 		|| data->mlx_data->key_state[123] || data->mlx_data->key_state[124])
// 	{
// 		if (data->mlx_data->key_state[0])
// 			move_player(data, WEST);
// 		if (data->mlx_data->key_state[2])
// 			move_player(data, EAST);
// 		if (data->mlx_data->key_state[1])
// 			move_player(data, SOUTH);
// 		if (data->mlx_data->key_state[13])
// 			move_player(data, NORTH);
// 		if (data->mlx_data->key_state[123])
// 			rotate_player(data, WEST);
// 		if (data->mlx_data->key_state[124])
// 			rotate_player(data, EAST);
// 		mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
// 		draw_map(data);
// 	}
// 	return (0);
// }

// int	loop_hook(t_data *data)
// {
// 	mlx_hook(data->mlx_data->mlx_win, 2, 0, key_hook, data);
// 	mlx_hook(data->mlx_data->mlx_win, 3, 0, key_release, data);
// 	mlx_hook(data->mlx_data->mlx_win, 17, 0, destroy_window_x, data);
// 	move_hook(data);
// 	return (0);
// }

int	key_hook(int key, t_data *data)
{
	if (key == 0 || key == 2 || key == 1 || key == 13
		|| key == 123 || key == 124)
	{
		if (key == 0)
			move_player(data, WEST);
		if (key == 2)
			move_player(data, EAST);
		if (key == 1)
			move_player(data, SOUTH);
		if (key == 13)
			move_player(data, NORTH);
		if (key == 123)
			rotate_player(data, WEST);
		if (key == 124)
			rotate_player(data, EAST);
		mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
		draw_map(data);
	}
	key_hook_destroy(key, data->mlx_data);
	return (0);
}

int	loop_hook(t_data *data)
{
	mlx_hook(data->mlx_data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_data->mlx_win, 17, 0, destroy_window_x, data);
	return (0);
}