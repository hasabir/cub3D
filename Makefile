# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2023/04/08 11:19:50 by hasabir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

NAME_BONUS = cub3D_bonus


MSRCS = parser_textures.c parser_textures_2.c get_next_line.c \
	ft_split.c ft_utils_2.c ft_utils_3.c\
	ft_utils.c parser_map.c parser_map_2.c ft_split_textures.c\
	mlx_init.c map_data.c mlx_hooks.c\
	move_player.c ray_casting.c ray_casting_utils.c\
	mlx_hooks_utils.c init_textures.c randring_wall.c \
	move_player_utils.c color.c parsing.c

SRCS = main.c ${MSRCS}

SRCS_BONUS = ${MSRCS} draw_minimap_bonus.c main_bonus.c draw_line_bonus.c\
	mlx_hooks_bonus.c

OBJ_D = obj

OBJS = $(addprefix $(OBJ_D)/,${SRCS:.c=.o})

OBJS_BONUS = $(addprefix $(OBJ_D)/,${SRCS_BONUS:.c=.o})

CC = cc

MLXFLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(OBJ_D)/%.o:  %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME} :${OBJS}
	@$(CC) $(OBJS) ${MLXFLAGS} -o $(NAME)
	@echo "|  Compilation Done  |"

bonus : ${NAME_BONUS}

$(OBJ_D)/%.o:  %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME_BONUS} :${OBJS_BONUS}
	@$(CC) $(OBJS_BONUS) ${MLXFLAGS} -o $(NAME_BONUS)
	@echo "| Bonus compilation Done  |"

${OBJ_D} :
	@mkdir ${OBJ_D}

clean:
	@rm -rf ${OBJ_D}
	@echo "|  CLEANED |"

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${NAME_BONUS}
re: fclean all
