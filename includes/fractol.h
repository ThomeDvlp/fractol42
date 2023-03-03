/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:44:33 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/03 16:31:02 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define W 500
# define MAX_ITER 1000

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	double	red;
	double	green;
	double	blue;
	double	h;
	double	s;
	double	v;
	double	f;
	double	p;
	double	q;
	double	t;
	int		i;
	int		rgb;
} t_color;

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	int		x;
	int		y;
	int		iter;
	int		render;
	int		what_fractol;
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
} t_fractal;


#endif