/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:57 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/14 15:20:57 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <mlx.h>
# include<math.h>

enum colors
{
	RED = 0x00FF0000,
	GREEN = 0x0000FF00, 
	BLUE = 0x000000FF,
	BLACK = 0x000000 ,
	WIGHT = 0xFFFFFF
};

enum movement
{
	LEFT,
	RIGHT,
	FORWARD,
	BACK,
	ROTATE
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
	int		player_x;
	int		player_y;
	
}t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		size_x;
	int		size_y;
	t_img 	*img;
}t_mlx;

struct s_coordinate
{
	// int	z1;
	// int	z2;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	px;
	int	py;
};
typedef struct s_coordinate	t_coordinate;

typedef struct s_data
{
	int		fd;
	char	**line;
	char	**identifier;
	char	**tab_identifier;
	char	*init_map;
	char	**textures;
	char	**map;
	t_mlx	*mlx_data;
	t_player player;
	t_coordinate coordinate;
} t_data;


/*******************************************************************************/

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	parse_texture(t_data **data);
// void	parse_texture(t_data *data);
void	parse_map(char **map);
int		ft_atoi(const char	*str);
int		len_tab(char **tab_identifier);
int		ft_isum(int c);
int		is_whitespace(char c);
char	**ft_split(char const *s, char c);
char	**ft_split_textures(char const *s);
void	remove_space(char **line);
void	ft_error(char *error);
void	check_whitespace(t_data *data,
			int *other_whitespace, char **tmp);

/**************************** mlx_init.c ****************************************/

void	set_mlx_data(t_data *data);
void	my_pixel_put(t_mlx *mlx_data, int x, int y, int color);

/**************************** map_data ******************************************/

int	get_size_y(char **map);
int get_size_x(char **map);
void get_player_position(t_data *data);

/**************************** draw_map_2D.c *************************************/

void	draw_map(t_data *data);

/**************************** mlx_hook.c ****************************************/

int	distroy_window_x();
int	key_hook_destroy(int key, t_mlx *mlx_data);
int	loop_hook(t_data *data);
int	loop_hook(t_data *mlx_data);

/**************************** move_player.c ************************************/

void move_player(t_data *data, int type);

/**************************** draw_line.c **************************************/

int	line_draw(t_data *data);

# endif

// F 220, 100, 0
// C 255, 30, 0
// "editor.cursorSmoothCaretAnimation": "on",