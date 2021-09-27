#ifndef SOLONG_H
# define SOLONG_H

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH 600
#define WIN_HEIGHT 600

#define IMG_WIDTH 600
#define IMG_HEIGHT 600

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}			t_mlx;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef	struct game
{
	int	data;
	int	x;
	int y;
	int	wall;
	int collect;
	int	exit;
	int	player;
	int space;

	t_mlx	*mlx;
	t_img	img;

}	t_game;

#endif
