#include "solong.h"
#include "./libft/libft.h"

void	window_init(t_game *game)
{
	game->mlx->mlx_ptr = mlx_init();
	game->mlx->win = mlx_new_window(game->mlx->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "so_long");
}

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, \
	&game->img.bpp, &game->img.size_l, &game->img.endian);
}


int main()
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	game->mlx = malloc(sizeof(void *) * 1);
	// initialize_variables(game);
	window_init(game);
	img_init(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, "./images/chao1.xpm", 0, 0);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
	game->img.img_ptr, 0, 0);
	mlx_loop(game->mlx->mlx_ptr);
	return(0);
}
