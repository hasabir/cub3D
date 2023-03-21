# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2023/03/18 13:04:42 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

SRCS = parser_textures.c parser_textures_2.c main.c get_next_line.c \
	ft_split.c ft_utils_2.c ft_utils_3.c\
	ft_utils.c parser_map.c parser_map_2.c ft_split_textures.c\
	mlx_init.c map_data.c draw_map_2D.c mlx_hooks.c\
	move_player.c draw_line.c ray_casting.c

OBJ_D = obj

OBJS = $(addprefix $(OBJ_D)/,${SRCS:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(OBJ_D)/%.o:  %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME} :${OBJS}
	@$(CC) $(OBJS) -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "|  Compilation Done  |"
${OBJ_D} :
	@mkdir ${OBJ_D}

clean:
	@rm -rf ${OBJ_D}
	@echo "|  CLEANED |"

fclean: clean
	@rm -rf ${NAME}

re: fclean all
