/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:27:37 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/08 10:34:41 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	mouse_hook(int mouse_button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mouse_button == 1)
		data->mlx_data->key_state.m_trigonometric_rotation = 1;
	if (mouse_button == 2)
		data->mlx_data->key_state.m_clockwise_rotation = 1;
	speed_control(0, data, mouse_button);
	return (0);
}

int	mouse_release(int mouse_button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mouse_button == 1)
		data->mlx_data->key_state.m_trigonometric_rotation = 0;
	if (mouse_button == 2)
		data->mlx_data->key_state.m_clockwise_rotation = 0;
	return (0);
}
