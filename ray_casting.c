/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:53:22 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/26 17:24:30 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// void	cast_rays(t_data *data)
// {
// 	long double	angle;
// 	int nbr_rays;

// 	nbr_rays = data->mlx_data->size_x;
// 	angle = data->player.angle - M_PI / 6;
// 	int i;
// 	i = 0;
// 	while (angle <= (data->player.angle + M_PI / 6))
// 	{
// 		data->coordinate.x2 = data->coordinate.x1;
// 		data->coordinate.y2 = data->coordinate.y1;
// 		while (data->map[(int)(data->coordinate.y2 / 30)]
// 			[(int)(data->coordinate.x2 / 30)] != '1')
// 		{
// 			data->coordinate.y2 -= sin(angle);
// 			data->coordinate.x2 += cos(angle);
// 		}
// 		line_draw(data);
// 		angle += 0.001;
// 	}

	
// }

void	cast_rays(t_data *data)
{
	long double	angle;
	int nbr_rays;

	nbr_rays = data->mlx_data->size_x * 30;
	double fov = (M_PI / 3);
	angle = data->player.angle - fov / 2;
	int i;
	i = 0;
	while (i <= nbr_rays)
	{
		data->coordinate.x2 = data->coordinate.x1;
		data->coordinate.y2 = data->coordinate.y1;
		while (data->map[(int)(data->coordinate.y2 / 30)]
			[(int)(data->coordinate.x2 / 30)] != '1')
		{
			data->coordinate.y2 -= sin(angle);
			data->coordinate.x2 += cos(angle);
		}
		line_draw(data);
		angle += fov / nbr_rays;
		i++;
	}
}

void	find_direction(t_data *data, int *direction_x, int *direction_y)
{
	if (data->player.angle >= 0 && data->player.angle <= M_PI_2)
	{
		*direction_x = 1;
		*direction_y = -1;
	}
	else if (data->player.angle > M_PI_2 && data->player.angle <= M_PI)
	{
		*direction_x = -1;
		*direction_y = -1;
	}
	else if (data->player.angle > M_PI && data->player.angle <= 3 * M_PI / 2)
	{
		*direction_x = -1;
		*direction_y = 1;
	}
	else if (data->player.angle > 3 * M_PI / 2 && data->player.angle < 0)
	{
		*direction_x = 1;
		*direction_y =  1;
	}
}

void	find_first_x_intersection(t_data *data, double angle, int direction_x, int direction_y)
{
	(void)direction_y;
	data->coordinate.y2 = (int)(data->coordinate.y1 / 30) * 30;
	if (angle == M_PI_2)
		data->coordinate.x2 = data->coordinate.x1
			+ direction_x * (data->coordinate.y1 - data->coordinate.y2);
	else
		data->coordinate.x2 = data->coordinate.x1
			+ direction_x * (data->coordinate.y1 - data->coordinate.y2) / tan(angle);
}

void	find_first_y_intersection(t_data *data, double angle, int direction_x, int direction_y)
{

	double x1;
	x1 = data->coordinate.x2;
	(void)direction_x;
	data->coordinate.x2 = (int)(data->coordinate.x2 / 30) * 30 + 30;
	if (angle == M_PI_2)
		data->coordinate.y2 = data->coordinate.y2
			+ direction_y * (data->coordinate.x2 - x1);
	else
		data->coordinate.y2 = data->coordinate.y2
			+ direction_y * (data->coordinate.x2 - x1) * tan(angle);
}

void	cast_ray(t_data *data, double angle)
{
	int	dx;
	int	dy;
	int	direction_x;
	int	direction_y;
	long double x2;
	long double y2;

	// if (angle == M_PI_2)
	// 	dx = 30;
	// else
		dx = 30 / tan(angle);
	// if (angle == M_PI_2)
	// 	dy = 30;
	// else
		dy = 30 * tan(angle);
	direction_x = 0;
	direction_y = 0;
	find_direction(data, &direction_x, &direction_y);
	find_first_x_intersection(data, angle, direction_x, direction_y);
	x2 = data->coordinate.x2;
	y2 = data->coordinate.y2;
	while (data->map[(int)(y2 / 30)]
			[(int)(x2 / 30)] != '1')
	{
		find_direction(data, &direction_x, &direction_y);
		x2 += direction_x * dx;
		y2 += direction_y * 30;
	}
	find_first_y_intersection(data, angle, direction_x, direction_y);
	while (data->map[(int)(data->coordinate.y2 / 30)]
			[(int)(data->coordinate.x2 / 30)] != '1')
	{
		find_direction(data, &direction_x, &direction_y);
		data->coordinate.x2 += direction_x * 30;
		data->coordinate.y2 += direction_y * dy;
	}
	// double distance_1;
	// double distance_2;

	// distance_1 = sqrt((x2 - data->coordinate.x1) * (x2 - data->coordinate.x1)
	// 			+ (y2 - data->coordinate.y1) * (y2 - data->coordinate.y1));
	// distance_2 = sqrt((data->coordinate.x2 - data->coordinate.x1)
	// 				* (data->coordinate.x2 - data->coordinate.x1)
	// 				+ (data->coordinate.y2 - data->coordinate.y1)
	// 				* (data->coordinate.y2 - data->coordinate.y1));
	// if (distance_1 < distance_2)
	// {
	// 	data->coordinate.x2 = x2;
	// 	data->coordinate.y2 = y2;
	// }
	
}

// void	cast_rays(t_data *data)
// {
// 	long double	angle;
// 	int nbr_rays;

// 	nbr_rays = data->mlx_data->size_x * 30;
// 	double fov = (M_PI / 3);
// 	angle = data->player.angle - fov / 2;
// 	int i;
// 	i = 0;
// 	// while (i <= nbr_rays)
// 	// {
// 	// 	// angle = data->player.angle;//!
// 		cast_ray(data, angle);
// 		line_draw(data);
// 		angle += fov / nbr_rays;
// 		i++;
// 	// }
// }
//! Digital Differential Analysis

// void cast_ray(t_data *data)
// {
// 	double dir_x;
// 	double dir_y;
	

// 	dir_x = -1;//?
// 	dir_y = 0; //?
	
// }














//! 10
//! 01
//! 10
