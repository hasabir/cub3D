/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:47:22 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/08 12:04:26 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include "cub.h"

int	mouse_hook(int mouse_button, int x, int y, t_data *data);
int	mouse_release(int mouse_button, int x, int y, t_data *data);
int	line_draw(t_data *data);

#endif