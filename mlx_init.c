/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:20:33 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/11 09:49:28 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_player_data(t_data *data)
{
	get_player_position(data);
	data->coordinate.x1 = data->player.player_x;
	data->coordinate.y1 = data->player.player_y;
	data->player.speed = 5;
	data->player.rotation_speed = 10;
	if (data->player.direction == 'N')
		data->player.angle = M_PI / 2;
	if (data->player.direction == 'S')
		data->player.angle = 3 * M_PI / 2;
	if (data->player.direction == 'E')
		data->player.angle = M_PI;
	if (data->player.direction == 'W')
		data->player.angle = M_PI * 2;
}

void	init_walls_data(t_data *data)
{
	data->walls = malloc(sizeof(t_wall));
	if (!data->walls)
		return ;
	data->walls->height_2_d = 0;
	data->walls->dist_3_d = 0;
	data->walls->height_wall = 0;
	data->walls->start = 0;
	data->walls->end = 0;
}

void	set_mlx_data(t_data *data)
{
	data->mlx_data = malloc(sizeof(t_mlx));
	if (!data->mlx_data)
		exit(EXIT_FAILURE);
	data->mlx_data->img = malloc(sizeof(t_img));
	if (!data->mlx_data->img)
		exit(EXIT_FAILURE);
	data->mlx_data->mlx = mlx_init();
	data->player.player_x = 0;
	data->player.player_y = 0;
	data->mlx_data->size_x = get_size_x(data->map);
	data->mlx_data->size_y = get_size_y(data->map) - 1;
	data->mlx_data->window_width = 1500;
	data->mlx_data->window_hight = 1000;
	data->mlx_data->mlx_win = mlx_new_window(data->mlx_data->mlx,
			data->mlx_data->window_width,
			data->mlx_data->window_hight, "Cub3D");
	data->mlx_data->block_x = 50;
	data->mlx_data->block_y = 50;
	init_player_data(data);
	init_walls_data(data);
	init_key_state(data);
}

void	init_image(t_data *data)
{
	data->mlx_data->img->mlx_img = mlx_new_image(data->mlx_data->mlx,
			data->mlx_data->window_width, data->mlx_data->window_hight);
	data->mlx_data->img->img_addr = mlx_get_data_addr(
			data->mlx_data->img->mlx_img, &data->mlx_data->img->bpp,
			&data->mlx_data->img->line_len, &data->mlx_data->img->endian);
}

void	my_pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= mlx_data->window_hight
		|| x < 0 || x >= mlx_data->window_width)
		return ;
	dst = mlx_data->img->img_addr + (
			y * mlx_data->img->line_len + x * (mlx_data->img->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}
