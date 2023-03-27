/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:08:03 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/27 07:43:36 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


void	draw_player(t_data *data, int *x, int step_y)
{
	double	i;
	double	j;
	int		step_x;

	i = data->coordinate.x1 - 5;
	while (i < data->coordinate.x1 + 5)
	{
		j = data->coordinate.y1 - 5;
		while (j < data->coordinate.y1 + 5)
		{
			my_pixel_put(data->mlx_data, i, j, RED);
			j++;
		}
		i++;
	}
	cast_rays(data);
	step_x = *x + 30;
	while (*x < step_x)
	{
		my_pixel_put(data->mlx_data, *x, step_y, WIGHT);
		(*x)++;
	}
	int y = step_y - 30;
	while (y < step_y)
	{
		my_pixel_put(data->mlx_data, *x, y, WIGHT);
		y++;
	}
}

void	draw_wall(t_mlx *mlx_data, int *x, int step_y)
{
	int	step_x;
	int	y;

	step_x = *x + 30;
	while (*x < step_x)
	{
		y = step_y - 30;
		while (y < step_y)
		{
			my_pixel_put(mlx_data, *x, y, GREEN);
			y++;
		}
		(*x)++;
	}
}

void	skip(t_data *data, int step_y, int *x)
{
	int	step;
	int y;

	step = *x + 30;
	while (*x < step)
	{
		my_pixel_put(data->mlx_data, *x, step_y, WIGHT);
		(*x)++;
	}
	y = step_y - 30;
	while (y < step_y)
	{
		my_pixel_put(data->mlx_data, *x, y, WIGHT);
		y++;
	}
}

void	draw_block(t_data *data, int line, int step_y)
{
	int	x;
	int	colon;

	x = 0;
	colon = 0;
	while (data->map[line] && colon < data->mlx_data->size_x
		&& data->map[line][colon])
	{
		if (data->map[line][colon] == ' ' || data->map[line][colon] == '0')
			skip(data, step_y, &x);
			// skip(&x);
		else if (data->map[line][colon] == '1')
			draw_wall(data->mlx_data, &x, step_y);
		else if (data->map[line][colon] == 'N'
				|| data->map[line][colon] == 'S'
				|| data->map[line][colon] == 'W'
				|| data->map[line][colon] == 'E')
			draw_player(data, &x, step_y);
		colon++;
	}
}

void	draw_map(t_data *data)
{
	int	step_y;
	int	line;

	init_image(data);
	line = 0;
	step_y = 30;
	while (line < data->mlx_data->size_y)
	{
		draw_block(data, line, step_y);
		line++;
		step_y += 30;
	}
	mlx_put_image_to_window(data->mlx_data->mlx,
		data->mlx_data->mlx_win, data->mlx_data->img->mlx_img, 0, 0);
}

// void	draw_player(t_data *data, int *x)
// {
// 	double	i;
// 	double	j;
// 	int		step_x;

	// i = data->coordinate.x1 - 5;
	// while (i < data->coordinate.x1 + 5)
	// {
	// 	j = data->coordinate.y1 - 5;
	// 	while (j < data->coordinate.y1 + 5)
	// 	{
	// 		my_pixel_put(data->mlx_data, i, j, RED);
	// 		j++;
	// 	}
	// 	i++;
	// }
// 	cast_rays(data);
// 	step_x = *x + 30;
// 	while (*x < step_x)
// 		(*x)++;
// }

// void	draw_wall(t_mlx *mlx_data, int *x, int step_y)
// {
// 	int	step_x;
// 	int	y;

// 	step_x = *x + 30;
// 	while (*x < step_x)
// 	{
// 		y = step_y - 30;
// 		while (y < step_y)
// 		{
// 			my_pixel_put(mlx_data, *x, y, GREEN);
// 			y++;
// 		}
// 		(*x)++;
// 	}
// }

// void	skip(int *x)
// {
// 	int	step;

// 	step = *x + 30;
// 	while (*x < step)
// 		(*x)++;
// }

// void	draw_block(t_data *data, int line, int step_y)
// {
// 	int	x;
// 	int	colon;

// 	x = 0;
// 	colon = 0;
// 	while (data->map[line] && colon < data->mlx_data->size_x
// 		&& data->map[line][colon])
// 	{
// 		if (data->map[line][colon] == ' ' || data->map[line][colon] == '0')
// 			skip(&x);
// 		else if (data->map[line][colon] == '1')
// 			draw_wall(data->mlx_data, &x, step_y);
// 		else if (data->map[line][colon] == 'N'
// 				|| data->map[line][colon] == 'S'
// 				|| data->map[line][colon] == 'W'
// 				|| data->map[line][colon] == 'E')
// 			draw_player(data, &x);
// 		colon++;
// 	}
// }

// void	draw_map(t_data *data)
// {
// 	int	step_y;
// 	int	line;

// 	init_image(data);
// 	line = 0;
// 	step_y = 30;
// 	while (line < data->mlx_data->size_y)
// 	{
// 		draw_block(data, line, step_y);
// 		line++;
// 		step_y += 30;
// 	}
// 	mlx_put_image_to_window(data->mlx_data->mlx,
// 		data->mlx_data->mlx_win, data->mlx_data->img->mlx_img, 0, 0);
// }
