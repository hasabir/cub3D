/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:53:22 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 09:57:49 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

long double	cast_ray(t_data *data, long double angle)
{
	long double	horizontal_distance;
	long double	vertical_distance;

	find_direction(data, &angle);
	horizontal_distance = find_horizontal_intersection(data, angle);
	vertical_distance = find_vertical_intersection(data, angle);
	if (horizontal_distance < vertical_distance)
	{
		data->coordinate.y2 = data->ray.y2_horizontal;
		data->coordinate.x2 = data->ray.x2_horizontal;
		data->ray.flag_h_v = 1;
		return (horizontal_distance);
	}
	data->coordinate.y2 = data->ray.y2_vertical;
	data->coordinate.x2 = data->ray.x2_vertical;
	data->ray.flag_h_v = 0;
	return (vertical_distance);
}

void	cast_rays(t_data *data)
{
	long double	angle;
	long double	distance;
	long double	i;
	long double	fov;
	int			nbr_rays;

	nbr_rays = data->mlx_data->window_width;
	fov = (M_PI / 3);
	angle = data->player.angle - fov / 2;
	i = -1;
	while (++i < nbr_rays)
	{
		distance = cast_ray(data, angle);
		distance *= cos(angle - data->player.angle);
		rendering_wall(distance, data);
		angle += fov / nbr_rays;
	}
}
