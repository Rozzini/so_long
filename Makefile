# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraspors <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:06:52 by mraspors          #+#    #+#              #
#    Updated: 2022/06/24 06:39:02 by mraspors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

FLAGS = -crs

mlx = ./mlx/libmlx.a

FILES = ./src/mandatory/parsing/read_split.c ./src/mandatory/parsing/check_map1.c ./src/mandatory/parsing/check_map2.c\
		./src/mandatory/drawnfree/draw.c ./src/mandatory/drawnfree/free.c\
		./src/mandatory/init/initData.c ./src/mandatory/move/move.c\
		so_long.c
		
FILES_BONUS = ./src/bonus/parsing/read_split.c ./src/bonus/parsing/check_map1.c ./src/bonus/parsing/check_map2.c\
		./src/bonus/drawnfree/draw.c ./src/bonus/drawnfree/free.c\
		./src/bonus/init/initData1.c ./src/bonus/init/initData2.c\
		./src/bonus/move/move1.c ./src/bonus/move/move2.c\
		so_long_bonus.c

OBJECTS = $(FILES:.c=.o)

OBJECTS = $(FILES_BONUS:.c=.o)

LIBFT = cd libft && make

LIB = libft/libft.a

$(NAME)	:
		$(LIBFT)
		make -C ./mlx
		gcc $(CFLAGS) -o so_long $(FILES) $(LIB) $(mlx) -framework OpenGL -framework AppKit

bonus :
		$(LIBFT)
		make -C ./mlx
		gcc $(CFLAGS) -o so_long_bonus $(FILES_BONUS) $(LIB) $(mlx) -framework OpenGL -framework AppKit

all : $(NAME)

clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		rm -f so_long_bonus
		make clean -C mlx

re : fclean all

reb : fclean bonus