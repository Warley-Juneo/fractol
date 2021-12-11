/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/12/11 19:09:27 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 700
# define WIN_HEIGHT 700

# define IMG_WIDTH 700
# define IMG_HEIGHT 700

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_variables
{
	double			c_re;
	double			c_im;
	int				max_iter;
	double			x;
	double			y;
	int				iteration;
	int				row;
	int				col;
	int				mouse;
	double			scale;
	int				m_x2;
	int				m_y2;
	int				i;
	int				r;
	int				g;
	int				b;
	int				h;
	unsigned int	colors[255];
	int				indentify;
	t_img			img;
	t_mlx			*mlx;

}			t_variables;

void	initialize_variables(t_variables *var);
void	draw_scren(t_variables *var);
void	screen_to_world(t_variables *var, double *world_x, double *world_y);
void	generate_colors(t_variables *fractol);
void	zoom_aplication(t_variables *var, float factor);
int		mouse_event(int keycode, int x, int y, t_variables *var);
void	scree_to_julia(t_variables *var, double *world_x, double *world_y);
double	ft_atod(const char *nptr);
int		check_argument(int argc, char **argv, t_variables *var);
#endif
