/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:44:33 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/09 15:25:45 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define W 1280
# define H 720
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
}	t_color;

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
}	t_fractal;

void	ft_pixel_put(t_fractal *data, int x, int y, int color);

void	mlx_controller(t_fractal *fr);

void	case_1(t_color *color);

void	case_2(t_color *color);

void	hsv_to_rgb(t_color *color);

void	ft_rgb(t_color *color);

void	put_color(t_fractal *fr);

int		handle_keys(int button, t_fractal *fr);

int		handle_close(t_fractal *fr);

int		handle_mouse(int button, int x, int y, t_fractal *fr);

void	fractol_zoom_in(t_fractal *fr);

void	fractol_zoom_out(t_fractal *fr);

void	move(t_fractal *f, double distance, char direction);

void	draw_mandelbrot(t_fractal *fr);

void	draw_julia(t_fractal *fr);

void	test_julia(char *argv1, char *argv2);

double	fract_atoi(char *str);

#endif