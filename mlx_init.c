/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:20:33 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/27 14:22:48 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_player_data(t_data *data)
{
	get_player_position(data);
	data->coordinate.x1 = data->player.player_x + 5;
	data->coordinate.y1 = data->player.player_y + 5;
	data->player.speed = 2;
	if (data->player.direction == 'N')
		data->player.angle = M_PI / 2;
	if (data->player.direction == 'S')
		data->player.angle = 3 * M_PI / 2;
	if (data->player.direction == 'W')
		data->player.angle = M_PI;
	if (data->player.direction == 'E')
		data->player.angle = M_PI * 2;
}

void	set_mlx_data(t_data *data)
{
	data->mlx_data = malloc(sizeof(t_mlx));
	if (!data->mlx_data)
		exit(EXIT_FAILURE);
	data->mlx_data->mlx = mlx_init();
	data->player.player_x = 0;
	data->player.player_y = 0;
	data->mlx_data->size_x = get_size_x(data->map);
	data->mlx_data->size_y = get_size_y(data->map) - 1;
	data->mlx_data->mlx_win = mlx_new_window(data->mlx_data->mlx,
			data->mlx_data->size_x * 30,
			data->mlx_data->size_y * 30, "Cub3D");
	init_player_data(data);
}

void	init_image(t_data *data)
{
	data->mlx_data->img = malloc(sizeof(t_img));
	if (!data->mlx_data->img)
		exit(EXIT_FAILURE);
	data->mlx_data->img->mlx_img = mlx_new_image(data->mlx_data->mlx,
			data->mlx_data->size_x * 30, data->mlx_data->size_y * 30);
	data->mlx_data->img->img_addr = mlx_get_data_addr(
			data->mlx_data->img->mlx_img, &data->mlx_data->img->bpp,
			&data->mlx_data->img->line_len, &data->mlx_data->img->endian);
}

void	my_pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= mlx_data->size_y * 30
		|| x < 0 || x >= mlx_data->size_x * 30)
		return ;
	dst = mlx_data->img->img_addr + (
			y * mlx_data->img->line_len + x * (mlx_data->img->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}
