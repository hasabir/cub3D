/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:56:51 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/21 14:56:44 by hasabir          ###   ########.fr       */
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

// int key_hook(int key, t_data *data)
// {
// 	if (key == 0 || key == 2 || key == 1 || key == 13)
// 	{
// 		data->player.direction = 'T';
// 		if (key == 0)
// 			data->player.type = WEST;
// 		if (key == 2)
// 			data->player.type = EAST;
// 			// move_player(data, EAST);
// 		if (key == 1)
// 			data->player.type = SOUTH;
// 			// move_player(data, SOUTH);
// 		if (key == 13)
// 			data->player.type = NORTH;
// 			// move_player(data, NORTH);
// 		// mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
// 		// draw_map(data);
// 	}
// 	if (key == 123 || key == 124)
// 	{
// 		data->player.direction = 'R';
// 		if (key == 123)
// 			data->player.type = WEST;
// 			// rotate_player(data, WEST);
// 		if (key == 124)
// 			data->player.type = EAST;
// 		mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
// 			// rotate_player(data, EAST);
// 		// mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
// 	}
// 	key_hook_destroy(key, data->mlx_data);
// 	return (0);
// }

// int	loop_hook(t_data *data)
// {
// 	mlx_hook(data->mlx_data->mlx_win, 2, 0, key_hook, data);
// 	if (data->player.direction == 'T')
// 	{
// 		move_player(data, data->player.type);
// 		draw_map(data);
// 	}
// 	if (data->player.direction == 'R')
// 	{
// 		rotate_player(data, data->player.type);
// 		mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
// 		draw_map(data);
// 	}
// 	mlx_hook(data->mlx_data->mlx_win, 17, 0, destroy_window_x, data);
// 		// mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
// 	// draw_map(data);