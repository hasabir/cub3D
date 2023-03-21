/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:53:22 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/21 21:40:44 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	cast_rays(t_data *data)
{
	long double	angle;
	// int			block;

	angle = data->player.angle;
	// angle = data->player.angle - M_PI / 6;
	// while (angle <= (data->player.angle + M_PI / 6))
	// {
		data->coordinate.x2 = data->coordinate.x1;
		data->coordinate.y2 = data->coordinate.y1;
		// printf("size_x = %d\n", data->mlx_data->size_x);
		// printf("position x2 =  %lf\n", data->coordinate.x2 / 30);
		// printf("(int)position x2 =  %d\n", (int)data->coordinate.x2 / 30);
		// printf("position y2 =  %lf\n", data->coordinate.y2 / 30);
		while (data->map[(int)(data->coordinate.y2 / 30)]
			[(int)(data->coordinate.x2 / 30)] != '1')
		{
			data->coordinate.y2 -= sin(angle);
			data->coordinate.x2 += cos(angle);
		}
		line_draw(data);
	// 	angle += 0.001;
	// }
}
