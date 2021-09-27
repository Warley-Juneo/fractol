# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 19:41:51 by wjuneo-f          #+#    #+#              #
#    Updated: 2021/09/24 22:01:42 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a


MINILIBX_PATH	=./minilibx
MINILIBX	= $(MINILIBX_PATH)/libmlx.a

SOURCE			= solong.c


OBJECTS			= $(SOURCE:.c=.o)

HEADER			= solong.h
NAME			= solong

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
				clang -Wall -Werror -Wextra *c ./minilibx/libmlx.a -L. -lXext -L. -lX11 && ./a.out

norm:
				norminette *c && norminette ./libft/*c

.PHONY:			all clean fclean re run norm
