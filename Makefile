# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 19:41:51 by wjuneo-f          #+#    #+#              #
#    Updated: 2021/12/11 20:35:48 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a


MINILIBX_PATH	=./minilibx
MINILIBX	= $(MINILIBX_PATH)/libmlx.a

SOURCE			= fractol.c draw_scren.c initialize_variable.c aux.c
SOURCE			+= generate_colors.c mouse_event.c ft_atod.c check_arguments.c
SOURCE			+= check_param.c

OBJECTS			= $(SOURCE:.c=.o)

HEADER			= fractol.h
NAME			= fractol

CC				= clang
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror
MLXFLAGS		= -L. -lXext -L. -lX11

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)
		echo "$(GREEN)Project successfully compiled"

$(LIBFT):
			 	$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				echo "$(GREEN)Supressing libraries files$(CYAN)"
				make clean -C $(LIBFT_PATH)
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				echo "$(GREEN)Supressing libraries files$(CYAN)"
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re: fclean all

run:
				clang -Wall -Werror -Wextra -O3 *c ./libft/libft.a ./minilibx/libmlx.a -L. -lXext -L. -lX11 -lm

norm:
				norminette *c && norminette ./libft/*c

.PHONY:			all clean fclean re run norm
