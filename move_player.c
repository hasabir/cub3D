/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:14:10 by hasabir           #+#    #+#             */
/*   Updated: 2023/03/27 06:27:09 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	can_move(t_data *data, double player_x, double player_y, int *speed, int direction)
{

// 		int limit_y;
// 	// // double x;
// 	// // double y;
// 	int	limit_x;
// 	double	expected_collision_x;
// 	double	expected_collision_y;

	
// 	(void)speed;
// 	if (data->player.angle > M_PI / 4 && data->player.angle < M_PI / 4 + M_PI / 2)
// 	{
// 		// printf("^\n|\n");
// 		expected_collision_x =  player_x + (5 * direction) / tan(data->player.angle);
// 		expected_collision_y = player_y - 5;
// 		limit_y = (int)((expected_collision_y) / 30) * 30;
// 		if (data->map[limit_y / 30][(int)(expected_collision_x / 30)] == '1')
// 		{
// 			if ((int)((expected_collision_y)) != (limit_y + 30) - data->player.speed)
// 			{
// 				(*speed)--;
// 				return (2);
// 			}
// 		}
// 	}
// 	if (data->player.angle < M_PI / 4 && data->player.angle > M_PI / 4 - M_PI / 2)
// 	{
// 		// printf("->\n");
// 		expected_collision_x =  player_x + 5;
// 		expected_collision_y = player_y + (5 * direction) * tan(data->player.angle);
// 		limit_x = (int)((expected_collision_x) / 30) * 30;
// 		if (data->map[(int)(expected_collision_y / 30)][limit_x / 30] == '1')
// 		{
// 			if ((int)((expected_collision_y)) != (limit_x + 30) - data->player.speed)
// 			{
// 				(*speed)--;
// 				return (2);
// 			}
// 		}
// 	}
// 	if (data->player.angle > M_PI +  M_PI / 4 && data->player.angle < M_PI / 4 - M_PI / 2)
// 	{
// 		// printf("hellooo\n");
// 		// expected_collision_x =  player_x + (5 * direction) / tan(data->player.angle);
// 		// expected_collision_y = player_y - 5;
// 		// limit_y = (int)((expected_collision_y) / 30) * 30;
// 		// if (data->map[limit_y / 30][(int)(expected_collision_x / 30)] == '1')
// 		// {
// 		// 	if ((int)((expected_collision_y)) != (limit_y + 30) - data->player.speed)
// 		// 	{
// 		// 		(*speed)--;
// 		// 		return (2);
// 		// 	}
// 		// }	
// 	}
// 	// // if (data->player.angle > M_PI / 4 && data->player.angle < M_PI / 4 + M_PI / 2)
	// // {
	// // 	expected_collision_x =  player_x + (5 * direction) / tan(data->player.angle);
	// // 	expected_collision_y = player_y - 5;
	// // }
	// // if (data->player.angle > M_PI / 4 && data->player.angle < M_PI / 4 + M_PI / 2)
	// // {
	// // 	expected_collision_x =  player_x + (5 * direction) / tan(data->player.angle);
	// // 	expected_collision_y = player_y - 5;
	// // }

	// int limit_y;
	// double x;
	// double y;
	// int	limit_x;
	// double	expected_collision_x;
	// double	expected_collision_y;

	// // expected_collision_x =  player_x + (5 * direction) * cos(data->player.angle);

	
	
	// expected_collision_x =  player_x + (5 * direction	) / tan(data->player.angle);
	// expected_collision_y = player_y + (-direction) * ((5 * direction) / tan(data->player.angle)) * tan(data->player.angle);
	// limit_x = (int)((expected_collision_x) / 30) * 30;
	// limit_y = (int)((expected_collision_y) / 30) * 30;
	
	
	// if (data->map[limit_y / 30][(int)(expected_collision_x / 30)] == '1')
	// {
	// 	printf("i am here\n");
	// 	if ((int)((expected_collision_y)) != (limit_y + 30) - data->player.speed)
	// 	{
	// 		(*speed)--;
	// 		return (2);
	// 	}
	// }




	// x = player_x + (5 * direction) * cos(0);
	// y = (int)(player_y + (5 * (-direction)) * sin(0));
	// if (data->map[(int)(y / 30)][(int)(x / 30)] == '1')
	// {
	// 	printf("map[][] = %c\n", data->map[(int)(expected_collision_y / 30)][(int)(expected_collision_x / 30)]);
	// 	printf("|||||||||||\n");
	// 	return (0);
	// }
	// x = player_x + (5 * direction) * cos());
	// y = (int)(player_y + (5 * (-direction)) * sin());
	// if (data->map[(int)(y / 30)][(int)(x / 30)] == '1'
	// 	&& (int)((expected_collision_y)) != (limit_y + 30) - data->player.speed)
	// {
	// 	printf ("------------------>\n");
	// 	return (0);
	// }
	(void)speed;
	(void)direction;
	if (data->map[(int)(player_y / 30)][(int)(player_x / 30)] == '1')
		return (0);
	return (1);
}
	// //!check for angle + pi / 2
	// //!check for angle - pi / 2
	// //!check for angle + pi

void	rotate_player(t_data *data, int direction)
{
	if (direction == WEST)
		data->player.angle += data->player.speed * (M_PI / 180);
	if (direction == EAST)
		data->player.angle -= data->player.speed * (M_PI / 180);
}

// void	set_speed(t_data *data)
// {
// 	printf("%d - %d = %d\n",(int)data->coordinate.y1 + 5, (int)(data->coordinate.y1  / 30) * 30, (int)data->coordinate.y1 - (int)(data->coordinate.y1 / 30) * 30);
// }

int	move_up_down(t_data *data, int direction)
{
	double	player_x;
	double	player_y;
	int		canMove;
	int		speed;

	canMove = 2;
	speed = data->player.speed;
	// set_speed(data);
	while (canMove == 2)
	{
		player_x = data->coordinate.x1;
		player_y = data->coordinate.y1;
		player_x += (direction * speed * cos(data->player.angle));
		player_y += (direction * (-1)) * speed
			* sin(data->player.angle);
		canMove = can_move(data, player_x, player_y, &speed, direction);
	}
	if (!canMove)
		return (-1);
	data->coordinate.x1 = player_x;
	data->coordinate.y1 = player_y;
	return (1);
}

// int	move_up_down(t_data *data, int direction)
// {
// 	double	player_x;
// 	double	player_y;
// 	// int		speed;
// 	int		limit_x;
// 	int		limit_y;
// 	double		tmp_x;
// 	double		tmp_y;

// 	player_x = data->coordinate.x1;
// 	player_y = data->coordinate.y1;

// 	player_x += (direction * data->player.speed * cos(data->player.angle));
// 	player_y += (direction * (-1)) * data->player.speed
// 		* sin(data->player.angle);
// 	if (!can_move(data, &player_x, &player_y))
// 	{
// 		printf("\033[91mI told you !\n\033[00m");
// 		printf("\033[91mdistance x = %d, distance y = %d\n\033[00m", (int)player_x, (int)player_y);
// 		return (-1);
// 	}
	
	
// 	tmp_x = player_x + direction * data->player.speed * cos(data->player.angle);
// 	tmp_y = player_y + (direction * (-1)) * data->player.speed
// 		* sin(data->player.angle);
// 	limit_x = (int)(tmp_x / 30);
// 	limit_y = (int)(tmp_y / 30);
// 	// if (!can_move(data, &tmp_x, &tmp_y) || data->map[limit_y][limit_x] == '1')
// 	// {
// 		// printf("I won't move\n");
// 		// printf("distance x = %d, distance y = %d\n",(int)(player_x + direction * 10),(int)(player_y + direction * 10));
// 		printf("\n-----------------\n");
// 		printf("\033[93mtmp x = %d, tmp y = %d\n\033[00m", (int)tmp_x, (int)tmp_y);
// 		printf("limit x = %d ---- limit y = %d\n", limit_x * 30, limit_y * 30);
// 		printf("map[%d][%d] = %c\n", limit_y, limit_x,data->map[limit_y][limit_x]);
// 		if (tmp_y > (limit_y * 30) && tmp_y < (limit_y * 30) + 30)
// 		{
// 			if (direction == 1)
// 			{
// 				printf("up ---> %d < next_y = %d < %d\n", limit_y * 30,(int)tmp_y, (limit_y * 30) + 30);
// 				printf("up ---> %d < next_x = %d < %d\n", limit_x * 30,(int)tmp_x, (limit_x * 30) + 30);
// 			}
// 			if (direction == -1)
// 				printf("down ---> %d < tmp_y < %d\n", limit_y * 30, (limit_y * 30) + 30);
// 		}
// 	// }
// 	data->coordinate.x1 = player_x;
// 	data->coordinate.y1 = player_y;
// 	return (1);
// }

int	move_west_east(t_data *data, int direction)
{
	double	player_x;
	double	player_y;
	int		speed;

	speed = data->player.speed;
	player_x = data->coordinate.x1;
	player_y = data->coordinate.y1;
	player_x += direction * data->player.speed
		* cos(data->player.angle + M_PI / 2);
	player_y += (direction * (-1)) * data->player.speed
		* sin(data->player.angle + M_PI / 2);
	if (!can_move(data, player_x, player_y, &speed, direction))
		return (-1);
	data->coordinate.x1 = player_x;
	data->coordinate.y1 = player_y;
	return (1);
}

void	move_player(t_data *data, int type)
{
	// static	int will_move;

	if (type == SOUTH)
		move_up_down(data, -1);
	if (type == NORTH)
		move_up_down(data, 1);
	if (type == WEST)
		move_west_east(data, 1);
	if (type == EAST)
		move_west_east(data, -1);
}
