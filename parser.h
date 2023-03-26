/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:57 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/26 15:01:45 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <mlx.h>
# include<math.h>

enum e_colors
{
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF,
	BLACK = 0x000000,
	WIGHT = 0xFFFFFF,
	YELLOW = 0xFFFF00,
};

enum e_movement
{
	WEST,
	EAST,
	NORTH,
	SOUTH
};

typedef struct s_img
{
	void	*mlx_img;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;

typedef struct s_player
{
	long double		player_x;
	long double		player_y;
	long double		angle;
	char			direction;
	int				type;
	int				speed;
}t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		size_x;
	int		size_y;
	int		key_state[125];
	t_img	*img;
}t_mlx;

typedef struct s_coordinate
{
	long double		x1;
	long double		y1;
	long double		x2;
	long double		y2;
	int				ex;
	int				ey;
	int				dx;
	int				dy;
	int				px;
	int				py;
}	t_coordinate;

typedef struct s_data
{
	int				fd;
	int				other_whitespace;
	char			**line;
	char			**identifier;
	char			**tab_identifier;
	char			*init_map;
	char			**textures;
	char			**map;
	t_mlx			*mlx_data;
	t_player		player;
	t_coordinate	coordinate;
}	t_data;

/*************************************************************************/

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	parse_texture(t_data **data);
void	parse_map(char **map);
int		ft_atoi(const char	*str);
int		len_tab(char **tab_identifier);
int		ft_isum(int c);
int		is_whitespace(char c);
char	**ft_split(char const *s, char c);
char	**ft_split_textures(char *s);
void	remove_space_in_the_end(char **line);
void	ft_error(char *error);
void	check_whitespace(t_data *data,
			int *other_whitespace, char **tmp);
int		valid_char(char c);
void	check_first_char(char *line);
void	check_first_last_line(char *line);
void	check_surroundings_zero(char **map, int i, int j);
int		len_tab(char **tab_identifier);
char	**add_identifier(char **tab_identifier, char *identifier);
char	**check_dup(char **tab_identifier, char *identifier);
void	check_range_rgb(char **tab_rgb);
void	check_ceiling_floor(char *line);
void	ft_free(char **tab);
void	init_data(t_data *data, char **av);
char	**fill_tab_identifier(void);

/**************************** mlx_init.c ************************************/

void	set_mlx_data(t_data *data);
void	init_image(t_data *data);
void	my_pixel_put(t_mlx *mlx_data, int x, int y, int color);

/**************************** map_data **************************************/

int		get_size_y(char **map);
int		get_size_x(char **map);
void	get_player_position(t_data *data);

/**************************** draw_map_2D.c *********************************/

void	draw_map(t_data *data);

/**************************** mlx_hook.c *************************************/

int		destroy_window_x(void);
int		key_hook_destroy(int key, t_mlx *mlx_data);
int		loop_hook(t_data *data);
int		loop_hook(t_data *mlx_data);

/**************************** move_player.c **********************************/

void	move_player(t_data *data, int type);
void	rotate_player(t_data *data, int direction);
void	move_player(t_data *data, int type);

/**************************** draw_line.c ************************************/

int		line_draw(t_data *data);

/**************************** ray_casting.c **********************************/

void	cast_rays(t_data *data);

#endif
// "editor.cursorSmoothCaretAnimation": "on",
