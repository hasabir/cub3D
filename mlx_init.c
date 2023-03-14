/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:20:33 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/14 12:33:56 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"



void	set_mlx_data(t_data *data)
{
	data->mlx_data = malloc(sizeof(t_mlx));
		if (!data->mlx_data)
				exit(1);
	data->mlx_data->mlx = mlx_init();
	data->player.player_x = 0;
	data->player.player_y = 0;
	data->mlx_data->size_x = get_size_x(data->map);
	data->mlx_data->size_y = get_size_y(data->map);
	data->mlx_data->mlx_win = mlx_new_window(data->mlx_data->mlx, 
							data->mlx_data->size_x * 30,
							data->mlx_data->size_y * 30, "Cub3D");
	get_player_position(data);
	// draw_map(data);
	// mlx_loop_hook(data->mlx_data->mlx, loop_hook, data);
	// mlx_loop(data->mlx_data->mlx);
	
}

void	my_pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= mlx_data->size_y * 30
		|| x < 0 || x >= mlx_data->size_x * 30)
		return ;
	dst = mlx_data->img->img_addr + (y * mlx_data->img->line_len + x * (mlx_data->img->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}
