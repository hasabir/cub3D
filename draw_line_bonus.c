/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:02:31 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 12:12:53 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	creat_coordinate(t_data *data)
{
	data->coordinate.ex = fabsl(data->coordinate.x2 - data->coordinate.x1);
	data->coordinate.ey = fabsl(data->coordinate.y2 - data->coordinate.y1);
	data->coordinate.dx = data->coordinate.ex;
	data->coordinate.dy = data->coordinate.ey;
	return ;
}

void	first_case(t_data *data, int xi, int yi)
{
	int			i;
	long double	x1;
	long double	y1;

	i = 0;
	x1 = data->coordinate.x1;
	y1 = data->coordinate.y1;
	while (i <= data->coordinate.dx)
	{
		my_pixel_put(data->mlx_data, x1 * data->factor_x,
			y1 * data->factor_y, YELLOW);
		i++;
		x1 += xi;
		data->coordinate.ex -= data->coordinate.dy;
		if (data->coordinate.ex <= 1 / 2)
		{
			y1 += yi;
			data->coordinate.ex += data->coordinate.dx;
		}
	}
	return ;
}

void	second_case(t_data *data, int xi, int yi)
{
	int			i;
	long double	x1;
	long double	y1;

	i = 0;
	x1 = data->coordinate.x1;
	y1 = data->coordinate.y1;
	while (i <= data->coordinate.dy)
	{
		my_pixel_put(data->mlx_data, x1 * data->factor_x,
			y1 * data->factor_y, YELLOW);
		i++;
		y1 += yi;
		data->coordinate.ey -= data->coordinate.dx;
		if (data->coordinate.ey <= 1 / 2)
		{
			x1 += xi;
			data->coordinate.ey += data->coordinate.dy;
		}
	}
	return ;
}

int	line_draw(t_data *data)
{	
	int	xi;
	int	yi;

	xi = 1;
	yi = 1;
	creat_coordinate(data);
	if (data->coordinate.x1 > data->coordinate.x2)
		xi = -1;
	if (data->coordinate.y1 > data->coordinate.y2)
		yi = -1;
	if (data->coordinate.dx > data->coordinate.dy)
		first_case(data, xi, yi);
	else
		second_case(data, xi, yi);
	return (0);
}
