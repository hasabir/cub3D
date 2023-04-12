/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/08 12:14:45 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	loop_hook(t_data *data)
{
	mlx_hook(data->mlx_data->mlx_win, 4, 4, mouse_hook, data);
	mlx_hook(data->mlx_data->mlx_win, 5, 8, mouse_release, data);
	mlx_hook(data->mlx_data->mlx_win, 2, 1, key_hook, data);
	mlx_hook(data->mlx_data->mlx_win, 3, 2, key_release, data);
	mlx_hook(data->mlx_data->mlx_win, 17, 0, destroy_window_x, data);
	move_hook(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac != 2)
		ft_error("ERROR\n");
	init_data(data, av);
	ft_textures(data);
	set_colors(data);
	ft_map(data);
	close(data->fd);
	set_mlx_data(data);
	init_textures(data);
	draw_map(data);
	mlx_loop_hook(data->mlx_data->mlx, loop_hook, data);
	mlx_loop(data->mlx_data->mlx);
	ft_free(data->textures);
	ft_free(data->map);
	ft_free(data->identifier);
	ft_free(data->tab_identifier);
}
