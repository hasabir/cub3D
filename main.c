/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/25 21:46:58 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_textures(t_data *data)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = NULL;
	while (*(data->line))
	{
		free(*data->line);
		data->other_whitespace = 0;
		(*data->line) = get_next_line(data->fd);
		check_whitespace(data, &(data->other_whitespace), &tmp);
		if (ft_strcmp(*(data->line), "\n") && *tmp && !ft_isum(*tmp) && j < 7)
		{
			parse_texture(&data);
			data->textures[j++] = ft_strdup(*data->line);
		}
		else if (ft_strcmp(*(data->line), "\n")
			&& *tmp && ft_isum(*tmp) && !data->other_whitespace)
		{
			if (j != 6)
				ft_error("Number of textures not correct\n");
			data->textures[j] = NULL;
			break ;
		}
	}
}

void	ft_map(t_data *data)
{
	while (*(data->line))
	{
		data->init_map = ft_strjoin(data->init_map, *(data->line));
		free(*(data->line));
		*(data->line) = NULL;
		*(data->line) = get_next_line(data->fd);
		if (!*(data->line) || (*(data->line) && *(data->line)[0] == '\n'))
		{
			free (data->map);
			data->map = ft_split(data->init_map, '\n');
			parse_map(data->map);
			while (*(data->line) && *(data->line)[0] == '\n')
				*(data->line) = get_next_line(data->fd);
			break ;
		}
	}
	if (*(data->line))
	{
		free (*(data->line));
		ft_error("map_invalid\n");
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 2)
	{
		init_data(data, av);
		ft_textures(data);
		ft_map(data);
		close(data->fd);
		set_mlx_data(data);
		draw_map(data);
		mlx_loop_hook(data->mlx_data->mlx, loop_hook, data);
		mlx_loop(data->mlx_data->mlx);
		ft_free(data->textures);
		ft_free(data->map);
		ft_free(data->identifier);
		ft_free(data->tab_identifier);
	}
}

// #include "mlx.h"

// // Define the size of the key state array
// #define NUM_KEYS 256

// // Define a global array to keep track of the state of each key
// int key_state[NUM_KEYS];

// // Define a callback function for handling key events
// int key_callback(int keycode, void *param)
// {
//     // Set the state of the key to "pressed"
//     key_state[keycode] = 1;
    
//     return (0);
// }

// // Define a callback function for handling key release events
// int key_release_callback(int keycode, void *param)
// {
//     // Set the state of the key to "released"
//     key_state[keycode] = 0;
    
//     return (0);
// }

// // Main function
// int main()
// {
//     // Initialize MLX
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 640, 480, "Multi-key handling");
    
//     // Set the key event callbacks
//     mlx_hook(win, 2, 1, key_callback, NULL);
//     mlx_hook(win, 3, 2, key_release_callback, NULL);
    
//     // Enter the MLX event loop
//     mlx_loop(mlx);
    
//     return (0);
// }