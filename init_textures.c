/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:59:46 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/08 09:57:35 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*get_data_addr(t_img *image)
{
	return (mlx_get_data_addr(image->mlx_img, &image->bpp, &image->line_len,
			&image->endian));
}

void	init_img_addr(t_data *data)
{
	char	**path;
	int		i;

	i = -1;
	while (data->textures[++i])
	{
		path = ft_split_textures(data->textures[i], data);
		if (!ft_strcmp(path[0], "NO"))
			data->mlx_data->no_image->img_addr
				= get_data_addr(data->mlx_data->no_image);
		else if (!ft_strcmp(path[0], "SO"))
			data->mlx_data->so_image->img_addr
				= get_data_addr(data->mlx_data->so_image);
		else if (!ft_strcmp(path[0], "EA"))
			data->mlx_data->ea_image->img_addr
				= get_data_addr(data->mlx_data->ea_image);
		else if (!ft_strcmp(path[0], "WE"))
			data->mlx_data->we_image->img_addr
				= get_data_addr(data->mlx_data->we_image);
		ft_free(path);
	}
}

void	file_to_image(t_data *data, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image
		(data->mlx_data->mlx, path,
			&data->mlx_data->block_x, &data->mlx_data->block_y);
	if (!img->mlx_img)
		ft_error("ERROR\n");
}

void	init_mlx_img(t_data *data)
{
	char	**path;
	int		i;

	i = -1;
	while (data->textures[++i])
	{
		path = ft_split_textures(data->textures[i], data);
		if (!ft_strcmp(path[0], "NO"))
			file_to_image(data, data->mlx_data->no_image, path[1]);
		else if (!ft_strcmp(path[0], "SO"))
			file_to_image(data, data->mlx_data->so_image, path[1]);
		else if (!ft_strcmp(path[0], "EA"))
			file_to_image(data, data->mlx_data->ea_image, path[1]);
		else if (!ft_strcmp(path[0], "WE"))
			file_to_image(data, data->mlx_data->we_image, path[1]);
		ft_free(path);
	}
}

void	init_textures(t_data *data)
{
	data->mlx_data->no_image = malloc(sizeof(t_img));
	if (!data->mlx_data->no_image)
		exit(EXIT_FAILURE);
	data->mlx_data->so_image = malloc(sizeof(t_img));
	if (!data->mlx_data->so_image)
		exit(EXIT_FAILURE);
	data->mlx_data->we_image = malloc(sizeof(t_img));
	if (!data->mlx_data->we_image)
		exit(EXIT_FAILURE);
	data->mlx_data->ea_image = malloc(sizeof(t_img));
	if (!data->mlx_data->ea_image)
		exit(EXIT_FAILURE);
	init_mlx_img(data);
	init_img_addr(data);
}
