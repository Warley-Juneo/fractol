/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/21 19:41:44 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define IMG_WIDTH 1000
# define IMG_HEIGHT 1000

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_variables
{
	double	x_new;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		iteration;
	int		row;
	int		col;
	int		max;

	t_img	img;
	t_mlx	*mlx;

}			t_variables;

void	initialize_variables(t_variables *var);
void	draw_scren(t_variables *var);

#endif
