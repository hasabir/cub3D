/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:56:51 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/14 14:48:25 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	distroy_window_x()
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

int key_hook(int key, t_data *data)
{
	if (key == 0 || key == 2 || key == 1 || key == 13)
	{
		if (key == 0)
			move_player(data, LEFT);
		if (key == 2)
			move_player(data, RIGHT);
		if (key == 1)
			move_player(data, BACK);
		if (key == 13)
			move_player(data, FORWARD);
		mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
		draw_map(data);
	}
	key_hook_destroy(key, data->mlx_data);
	return (0);
}

int	loop_hook(t_data *data)
{
	mlx_hook(data->mlx_data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_data->mlx_win, 17, 0, distroy_window_x, data);
	return (0);
}