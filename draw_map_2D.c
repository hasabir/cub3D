/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:08:03 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/14 15:23:05 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void draw_player(t_data *data, int *x)
{
	int i ;
	int j ;
	int	step_x;

	i = data->player.player_x;
	while (i < data->player.player_x + 10)
	{
		j = data->player.player_y;
		while (j < data->player.player_y + 10)
		{
				my_pixel_put(data->mlx_data, i, j , RED);
			j++;
		}
		i++;
	}
	step_x = *x + 30;
	while (*x < step_x)
		(*x)++;
}

void draw_wall(t_mlx *mlx_data, int *x, int *step_y)
{
	int	step_x;
	int	y;

	step_x = *x + 30;
	while (*x < step_x)
	{
		y = *step_y - 30;
		while (y < *step_y)
		{
			my_pixel_put(mlx_data, *x, y , GREEN);
			(y)++;
		}
		(*x)++;
	}
}

void skip(int *x)
{
	int step;

	step = *x + 30;
	while (*x < step)
		(*x)++;
}


void	init_image(t_data *data)
{
	data->mlx_data->img = malloc(sizeof(t_img));
	if (!data->mlx_data->img)
		exit(EXIT_FAILURE);
	data->mlx_data->img->mlx_img = mlx_new_image(data->mlx_data->mlx, 
			data->mlx_data->size_x * 30, data->mlx_data->size_y * 30);
	data->mlx_data->img->img_addr = mlx_get_data_addr(data->mlx_data->img->mlx_img,
								&data->mlx_data->img->bpp,
							&data->mlx_data->img->line_len, &data->mlx_data->img->endian);
}

void	draw_map(t_data *data)
{
	int x;
	int step_y;
	int line;
	int colon;

	line = 0;
	init_image(data);
	step_y = 30;
	while (line < data->mlx_data->size_y)
	{
		colon = 0;
		x = 0;
		while (data->map[line] && colon < data->mlx_data->size_x && data->map[line][colon])
		{
			if (data->map[line][colon] == ' ' || data->map[line][colon] == '0')
				skip(&x);
			else if (data->map[line][colon] == '1')
				draw_wall(data->mlx_data, &x, &step_y);
			else if (data->map[line][colon] == 'N')
				draw_player(data, &x);
			colon ++;
		}
		line++;
		step_y += 30;
	}
	line_draw(data);
	mlx_put_image_to_window(data->mlx_data->mlx, 
					data->mlx_data->mlx_win, data->mlx_data->img->mlx_img, 0,0);
}