/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:10:05 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 09:57:49 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	find_direction(t_data *data, long double *angle)
{
	*angle = remainderl(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = 2 * M_PI + *angle;
	if (*angle > 0 && *angle < M_PI)
		data->ray.direction_y = -1;
	else
		data->ray.direction_y = 1;
	if (*angle >= M_PI_2 && *angle <= 1.5 * M_PI)
		data->ray.direction_x = -1;
	else
		data->ray.direction_x = 1;
}

void	find_first_x_intersection(t_data *data, long double angle)
{
	data->ray.y2_horizontal = floor(data->coordinate.y1 / 50) * 50;
	if (data->ray.direction_y == 1)
		data->ray.y2_horizontal += 50;
	data->ray.x2_horizontal = data->coordinate.x1
		+ ((data->coordinate.y1 - data->ray.y2_horizontal) / tan(angle));
}

void	find_first_y_intersection(t_data *data, long double angle)
{
	data->ray.x2_vertical = floorl(data->coordinate.x1 / 50) * 50;
	if (data->ray.direction_x == 1)
		data->ray.x2_vertical += 50;
	data->ray.y2_vertical = data->coordinate.y1
		- (data->ray.x2_vertical - data->coordinate.x1) * tan(angle);
}

long double	find_horizontal_intersection(t_data *data, long double angle)
{
	long double	step_x;
	long double	step_y;

	find_first_x_intersection(data, angle);
	step_x = 50 / tan(angle);
	if ((data->ray.direction_x == 1 && step_x < 0)
		|| (data->ray.direction_x == -1 && step_x > 0))
		step_x *= -1;
	step_y = 50 * data->ray.direction_y;
	if (data->ray.direction_y == -1)
		data->ray.y2_horizontal--;
	while (data->ray.x2_horizontal >= 0
		&& data->ray.x2_horizontal < data->mlx_data->size_x * 50
		&& data->ray.y2_horizontal >= 0
		&& data->ray.y2_horizontal < data->mlx_data->size_y * 50
		&& data->map[(int)(data->ray.y2_horizontal / 50)]
		[(int)(data->ray.x2_horizontal / 50)] != '1')
	{
			data->ray.x2_horizontal += step_x;
			data->ray.y2_horizontal += step_y;
	}
	if (data->ray.direction_y == -1)
		data->ray.y2_horizontal++;
	return (sqrt(pow(data->ray.x2_horizontal - data->coordinate.x1, 2)
			+ pow(data->ray.y2_horizontal - data->coordinate.y1, 2)));
}

long double	find_vertical_intersection(t_data *data, long double angle)
{
	long double	step_x;
	long double	step_y;

	find_first_y_intersection(data, angle);
	step_y = 50 * tan(angle);
	if ((data->ray.direction_y == -1 && step_y > 0)
		|| (data->ray.direction_y == 1 && step_y < 0))
		step_y *= -1;
	step_x = 50 * data->ray.direction_x;
	if (data->ray.direction_x == -1)
		data->ray.x2_vertical--;
	while (data->ray.x2_vertical >= 0
		&& data->ray.x2_vertical < data->mlx_data->size_x * 50
		&& data->ray.y2_vertical >= 0
		&& data->ray.y2_vertical < data->mlx_data->size_y * 50
		&& data->map[(int)(data->ray.y2_vertical / 50)]
		[(int)(data->ray.x2_vertical / 50)] != '1')
	{
		data->ray.x2_vertical += step_x;
		data->ray.y2_vertical += step_y;
	}
	if (data->ray.direction_x == -1)
		data->ray.x2_vertical++;
	return (sqrt(pow(data->ray.x2_vertical - data->coordinate.x1, 2)
			+ pow(data->ray.y2_vertical - data->coordinate.y1, 2)));
}
