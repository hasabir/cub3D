/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:29:53 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/08 12:16:26 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_range_rgb(char **tab_rgb)
{
	int	i;

	i = -1;
	while (tab_rgb[++i])
	{
		if (*tab_rgb[i] == '-'
			|| ft_atoi(tab_rgb[i]) < 0 || ft_atoi(tab_rgb[i]) > 255)
			ft_error("ERROR\n");
	}
}

void	set_color_ceiling(t_data *data)
{
	data->color->c_red = ft_atoi(data->color->rgb_ceiling[0]);
	data->color->c_green = ft_atoi(data->color->rgb_ceiling[1]);
	data->color->c_blue = ft_atoi(data->color->rgb_ceiling[2]);
	data->color->c_ceiling
		= data->color->c_red << 16
		| data->color->c_green << 8 | data->color->c_blue;
}

void	set_colors(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->textures && data->textures[++i])
	{
		j = -1;
		while (is_whitespace(data->textures[i][++j]))
			;
		if (data->textures[i][j] == 'F')
		{
			data->color->f_red = ft_atoi(data->color->rgb_floor[0]);
			data->color->f_green = ft_atoi(data->color->rgb_floor[1]);
			data->color->f_blue = ft_atoi(data->color->rgb_floor[2]);
			data->color->c_floor
				= data->color->f_red << 16
				| data->color->f_green << 8 | data->color->f_blue;
		}
		else
			set_color_ceiling(data);
	}
}

unsigned int	get_color(t_data *data, int offset_x, int offset_y, int flag)
{
	char	*dst;

	dst = NULL;
	if (offset_x < 0 || offset_x >= 50 || offset_y < 0 || offset_y >= 50)
		return (0);
	if (flag == SOUTH)
		dst = data->mlx_data->so_image->img_addr + (
				offset_y * data->mlx_data->so_image->line_len
				+ offset_x * (data->mlx_data->so_image->bpp / 8));
	else if (flag == NORTH)
		dst = data->mlx_data->no_image->img_addr + (
				offset_y * data->mlx_data->no_image->line_len
				+ offset_x * (data->mlx_data->no_image->bpp / 8));
	else if (flag == WEST)
		dst = data->mlx_data->we_image->img_addr + (
				offset_y * data->mlx_data->we_image->line_len
				+ offset_x * (data->mlx_data->we_image->bpp / 8));
	else if (flag == EAST)
		dst = data->mlx_data->ea_image->img_addr + (
				offset_y * data->mlx_data->ea_image->line_len
				+ offset_x * (data->mlx_data->ea_image->bpp / 8));
	return (*(unsigned int *)dst);
}
