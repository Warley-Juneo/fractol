# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 19:41:51 by wjuneo-f          #+#    #+#              #
#    Updated: 2021/10/01 20:31:35 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a


MINILIBX_PATH	=./minilibx
MINILIBX	= $(MINILIBX_PATH)/libmlx.a

SOURCE			= fractol.c draw_scren.c initialize_variable.c aux.c
SOURCE			+= generate_colors.c mouse_event.c


OBJECTS			= $(SOURCE:.c=.o)

HEADER			= fractol.h
NAME			= fractol

CC				= clang
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror
MLXFLAGS		= -L. -lXext -L. -lX11

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re: fclean all

run:
				clang -Wall -Werror -Wextra -O3 *c ./minilibx/libmlx.a -L. -lXext -L. -lX11 && ./a.out

norm:
				norminette *c && norminette ./libft/*c

.PHONY:			all clean fclean re run norm
