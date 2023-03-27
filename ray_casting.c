/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:53:22 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/27 16:09:33 by hasabir          ###   ########.fr       */
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

// void	cast_rays(t_data *data)
// {
// 	long double	angle;
// 	int nbr_rays;

// 	nbr_rays = data->mlx_data->size_x * 30;
// 	double fov = (M_PI / 3);
// 	angle = data->player.angle - fov / 2;
// 	int i;
// 	i = 0;
// 	while (i <= nbr_rays)
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
// 		angle += fov / nbr_rays;
// 		i++;
// 	}
// }

long double	find_direction(long double angle, int *direction_x, int *direction_y)
{
	angle = remainderl(angle, 2 * M_PI);
	if (angle < 0)
		angle = 2 * M_PI + angle;
	// if (angle > 0 && )
	if (angle > 0 && angle < M_PI_2)
	{
		*direction_x = 1;
		*direction_y = -1;
	}
	else if (angle >= M_PI_2 && angle < M_PI)
	{
		*direction_x = -1;
		*direction_y = -1;
	}
	else if (angle > M_PI && angle <= 1.5 * M_PI)
	{
		*direction_x = -1;
		*direction_y = 1;
	}
	else if (angle > 1.5 * M_PI && angle <= 2 * M_PI)
	{
		*direction_x = 1;
		*direction_y =  1;
	}
	return (angle);
}

void	find_first_x_intersection(t_data *data, double angle, int direction_x, int direction_y)
{
	(void)direction_x;
	(void)direction_y;
	data->coordinate.y2 = (int)(data->coordinate.y1 / 30) * 30;
	if (direction_y == 1)
		data->coordinate.y2 += 30;
	// printf("angle = ")
	if (angle == 2 * M_PI || angle == M_PI || angle == 0)
	{
		// data->coordinate.x2 = direction_x * data->mlx_data->size_x - x;
		data->coordinate.y2 = data->coordinate.y1;
		return ;
	}
	data->coordinate.x2 = data->coordinate.x1
		+ ((data->coordinate.y1 - data->coordinate.y2) / tan(angle));
}

void	find_first_y_intersection(t_data *data, double angle, int direction_x, int direction_y)
{
	data->coordinate.x2 = (int)(data->coordinate.x1 / 30) * 30;
	printf("direction x = %d\n", direction_x);
	if (direction_x == 1)
		data->coordinate.x2 += 30;
	data->coordinate.y2 = data->coordinate.y1
			+ direction_y * (data->coordinate.x2 - data->coordinate.x1) * tan(angle);
}

void	cast_ray(t_data *data, double angle)
{
	int	dx;
	// int	dy;
	int	direction_x;
	int	direction_y;
	long double x2;
	long double y2;
	int limit_x;
	int limit_y;
		
	// dy = 30 * tan(angle);
	direction_x = 0;
	direction_y = 0;
	angle = find_direction(angle, &direction_x, &direction_y);
	find_first_x_intersection(data, angle, direction_x, direction_y);
	x2 = data->coordinate.x2;
	y2 = data->coordinate.y2;
	dx = 30 / tan(angle);
	limit_x =(int)(x2 / 30);
	limit_y = (int)((y2) / 30);
	// fprintf(stderr, "x2 %Lf | y2 %Lf\n", x2, y2);
	// printf("limit x = %d | size_x = %d\n", limit_x, data->mlx_data->size_x);
	while (limit_x >= 0 && limit_x < data->mlx_data->size_x 
			&& limit_y < data->mlx_data->size_y && data->map[limit_y][limit_x] != '1')
	{
		x2 += direction_x * dx;
		y2 += direction_y * 30;
		limit_x =(int)(x2 / 30);
		limit_y = (int)((y2) / 30);
		if (direction_y == -1)
			limit_y--;
		printf("direction x = %d | direction y = %d\n", direction_x, direction_y);
	}
	// find_first_y_intersection(data, angle, direction_x, direction_y);
	// while (data->map[(int)(data->coordinate.y2 / 30)]
	// 		[(int)((data->coordinate.x2) / 30)] != '1')
	// {
	// 	dy = 30 * tan(angle);
	// 	data->coordinate.x2 += direction_x * 30;
	// 	data->coordinate.y2 += direction_y * dy;
	// }
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
		data->coordinate.y2 = y2;
		data->coordinate.x2 = x2;
	// }
	
}

void	cast_rays(t_data *data)
{
	long double	angle;
	int nbr_rays;

	nbr_rays = data->mlx_data->size_x * 30;
	double fov = (M_PI / 3);
	// angle = data->player.angle - fov / 2;
	angle = data->player.angle;
	int i;
	i = 0;
	// while (i <= nbr_rays)
	// {
		cast_ray(data, angle);
		line_draw(data);
		angle += fov / nbr_rays;
		i++;
	// }
}
//! Digital Differential Analysis
 














//! 10
//! 01
//! 10
