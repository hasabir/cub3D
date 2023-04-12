/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:08:03 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 12:13:21 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_player(t_data *data, long double *x)
{
	long double	step;
	long double	i;
	long double	j;

	i = data->coordinate.x1 - 5;
	while (i < data->coordinate.x1 + 5)
	{
		j = data->coordinate.y1 - 5;
		while (j < data->coordinate.y1 + 5)
		{
			my_pixel_put(data->mlx_data, i * data->factor_x,
				j * data->factor_y, RED);
			j++;
		}
		i++;
	}
	step = *x + data->mlx_data->block_x;
	while (*x < step)
		(*x)++;
}

void	draw_wall(t_data *data, long double *x, long double step_y)
{
	long double	step_x;
	long double	y;

	step_x = *x + data->mlx_data->block_x;
	while (*x < step_x)
	{
		y = step_y - data->mlx_data->block_y;
		while (y < step_y)
		{
			my_pixel_put(data->mlx_data, *x * data->factor_x,
				y * data->factor_y, RED);
			y++;
		}
		(*x)++;
	}
}

void	skip(t_data *data, long double *x)
{
	long double	step;

	step = *x + data->mlx_data->block_x;
	while (*x < step)
		(*x)++;
}

void	draw_block(t_data *data, int line, long double step_y)
{
	long double	x;
	int			colon;

	x = 0;
	colon = 0;
	while (data->map[line] && colon < data->mlx_data->size_x
		&& data->map[line][colon])
	{
		if (data->map[line][colon] == ' ' || data->map[line][colon] == '0')
			skip(data, &x);
		else if (data->map[line][colon] == '1')
			draw_wall(data, &x, step_y);
		else if (data->map[line][colon] == 'N'
				|| data->map[line][colon] == 'S'
				|| data->map[line][colon] == 'W'
				|| data->map[line][colon] == 'E')
			draw_player(data, &x);
		colon++;
	}
}

void	draw_map(t_data *data)
{
	long double	step_y;
	int			line;

	init_image(data);
	cast_rays(data);
	data->factor_x = 750 / data->mlx_data->size_x / 50 ;
	data->factor_y = 200 / data->mlx_data->size_y / 50;
	line = 0;
	step_y = data->mlx_data->block_y;
	while (line < data->mlx_data->size_y)
	{
		draw_block(data, line, step_y);
		line++;
		step_y += data->mlx_data->block_y;
	}
	cast_ray(data, data->player.angle);
	line_draw(data);
	mlx_put_image_to_window(data->mlx_data->mlx,
		data->mlx_data->mlx_win, data->mlx_data->img->mlx_img, 0, 0);
}
