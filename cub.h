/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:57 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/11 09:43:45 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

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
	RED = 0x660033,
	GREEN = 0x006600,
	BLUE = 0x3399FF,
	BLACK = 0x000000,
	WIGHT = 0xFFFFFF,
	YELLOW = 0xFFFFCC,
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
	int				rotation_speed;
}t_player;

typedef struct s_key
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	trigonometric_rotation;
	int	clockwise_rotation;
	int	m_trigonometric_rotation;
	int	m_clockwise_rotation;
}	t_key;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	long double		size_x;
	long double		size_y;
	int				block_x;
	int				block_y;
	long double		window_width;
	long double		window_hight;
	t_key			key_state;
	t_img			*no_image;
	t_img			*so_image;
	t_img			*we_image;
	t_img			*ea_image;
	t_img			*img;
}	t_mlx;

typedef struct s_ray_coordinates
{
	int			direction_x;
	int			direction_y;
	int			flag_h_v;
	long double	x2_horizontal;
	long double	y2_horizontal;
	long double	x2_vertical;
	long double	y2_vertical;
}	t_ray_coordinates;

typedef struct s_coordinate
{
	long double	x1;
	long double	y1;
	long double	x2;
	long double	y2;
	long double	ex;
	long double	ey;
	long double	dx;
	long double	dy;
}	t_coordinate;

typedef struct s_color
{
	char	**rgb_floor;
	char	**rgb_ceiling;
	int		f_red;
	int		f_green;
	int		f_blue;
	int		c_red;
	int		c_green;
	int		c_blue;
	int		c_floor;
	int		c_ceiling;
}	t_color;

typedef struct s_wall
{
	long double	height_2_d;
	long double	dist_3_d;
	long double	height_wall;

	long double	start;
	long double	end;
}	t_wall;

typedef struct s_data
{
	int					fd;
	int					nbr;
	int					itr;
	int					other_whitespace;
	char				**line;
	char				**identifier;
	char				**tab_identifier;
	char				*init_map;
	char				**textures;
	char				**map;
	long double			factor_x;
	long double			factor_y;
	t_mlx				*mlx_data;
	t_player			player;
	t_coordinate		coordinate;
	t_color				*color;
	t_wall				*walls;
	t_ray_coordinates	ray;
}	t_data;

/*************************************************************************/

char			*get_next_line(int fd);
char			*ft_strjoin(char *line, char *buff);
char			*ft_strdup(char *src);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			parse_texture(t_data **data);
void			parse_map(char **map);
int				ft_atoi(const char	*str);
int				len_tab(char **tab_identifier);
int				ft_isum(int c);
int				is_whitespace(char c);
char			**ft_split(char const *s, char c);
char			**ft_split_textures(char *s, t_data *data);
void			remove_space_in_the_end(char **line, int flag);
void			ft_error(char *error);
void			check_whitespace(t_data *data, char **tmp);
int				valid_char(char c);
void			check_first_char(char *line);
void			check_first_last_line(char *line);
void			check_surroundings_zero(char **map, int i, int j);
int				len_tab(char **tab_identifier);
char			**add_identifier(char **tab_identifier, char *identifier);
char			**check_dup(char **tab_identifier, char *identifier);
void			check_range_rgb(char **tab_rgb);
void			check_ceiling_floor(char **line, t_data *data);
void			ft_free(char **tab);
void			init_data(t_data *data, char **av);
char			**fill_tab_identifier(void);
int				check_file_name(char *file_name, char *extention);
void			set_colors(t_data *data);
void			init_textures(t_data *data);
unsigned int	get_color(t_data *data, int offset_x, int offset_y, int flag);
void			rendering_wall(long double ray_distance, t_data *data);
int				check_file_name(char *file_name, char *extention);
int				check_end_map(t_data *data);
void			check_end(char **map, int *i);
int				ft_end_stock_textures(t_data *data, char *tmp, int *j);
void			ft_textures(t_data *data);
void			ft_map(t_data *data);

/**************************** mlx_init.c ************************************/

void			set_mlx_data(t_data *data);
void			init_image(t_data *data);
void			my_pixel_put(t_mlx *mlx_data, int x, int y, int color);

/**************************** map_data **************************************/

int				get_size_y(char **map);
int				get_size_x(char **map);
void			get_player_position(t_data *data);

/**************************** mlx_hook.c *************************************/

int				destroy_window_x(void);
int				key_hook_destroy(int key, t_mlx *mlx_data);
int				key_hook(int key, t_data *data);
int				key_release(int key, t_data *data);

/*************************** mlx_hook_utils.c ********************************/

void			move_hook(t_data *data);
void			speed_control(int key, t_data *data, int mouse_button);
int				destroy_window_x(void);
void			init_key_state(t_data *data);

/**************************** move_player.c **********************************/

void			move_player(t_data *data, int type);
void			rotate_player(t_data *data, int direction);
void			move_player(t_data *data, int type);
void			move_u_d(t_data *data, double player_x,
					double player_y, int direction);
void			move_w_e(t_data *data, double player_x,
					double player_y, int direction);

/**************************** draw_line.c ************************************/

int				loop_hook(t_data *data);
void			draw_map(t_data *data);

/**************************** ray_casting.c **********************************/

void			cast_rays(t_data *data);
long double		cast_ray(t_data *data, long double angle);

/**************************** ray_casting_utils *****************************/

void			find_direction(t_data *data, long double *angle);
void			find_first_x_intersection(t_data *data, long double angle);
void			find_first_y_intersection(t_data *data, long double angle);
long double		find_horizontal_intersection(t_data *data, long double angle);
long double		find_vertical_intersection(t_data *data, long double angle);
#endif
