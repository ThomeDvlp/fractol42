/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:55:17 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/04 08:18:35 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bits / 8));
	*(unsigned int*)dst = color;
}
void	mlx_fractol(t_fractal *fr)
{
	fr->min_r = -2;
	fr->max_r = 2;
	fr->min_i = -1.5;
	fr->max_i = fr->min_i + (fr->max_r - fr->min_r) * ((double)W / (double)W);
	fr->render = 0;
	fr->mlx = mlx_init();
	fr->mlx_win = mlx_new_window(fr->mlx, W, W, "Fractol");
	fr->img = mlx_new_image(fr->mlx, W, W);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits, &fr->line, &fr->endian);
}
void	case_1(t_color *color)
{
	if (color->i == 0)
	{
		color->red = color->v;
		color->green = color->t;
		color->blue = color->p;
	}
	if (color->i == 1)
	{
		color->red = color->q;
		color->green = color->v;
		color->blue = color->p;
	}
	if (color->i == 2)
	{
		color->red = color->p;
		color->green = color->v;
		color->blue = color->t;
	}
}

void	case_2(t_color *color)
{
	if (color->i == 3)
	{
		color->red = color->p;
		color->green = color->q;
		color->blue = color->v;
	}
	if (color->i == 4)
	{
		color->red = color->t;
		color->green = color->p;
		color->blue = color->v;
	}
	if (color->i == 5)
	{
		color->red = color->v;
		color->green = color->p;
		color->blue = color->q;
	}
}

void	hsv_to_rgb(t_color *color)
{
	if (color->s == 0)
	{
		color->r = color->v;
		color->g = color->v;
		color->b = color->v;
	}
	else
	{
		if (color->h == 360)
			color->h = 0;
		else
			color->h = color->h / 60;
	}
	color->i = (int)trunc(color->h);
	color->f = color->h - color->i;
	color->p = color->v * (1.0 - color->s);
	color->q = color->v * (1.0 - (color->s * color->f));
	color->t = color->v * (1.0 - (color->s * (1.0 - color->f)));
	case_1(color);
	case_2(color);
	color->r = color->red * 255;
	color->g = color->green * 255;
	color->b = color->blue * 255;
}

void	ft_rgb(t_color *color)
{
	color->rgb = color->r;
	color->rgb = (color->rgb << 8) | color->g;
	color->rgb = (color->rgb << 8) | color->b;
}

void	put_color(t_fractal *fr)
{
	t_color	color;

	color.h = 100 * fr->iter;
	color.s = 0.5;
	color.v = 0.5;
	while (color.h > 360)
		color.h = color.h - 360;
	hsv_to_rgb(&color);
	ft_rgb(&color);
	ft_pixel_put(fr, fr->x, fr->y, color.rgb);
}

int	handle_keys(int button, t_fractal *fr)
{
	if (button == 53)
	{
		mlx_destroy_image(fr->mlx, fr->img);
		mlx_destroy_window(fr->mlx, fr->mlx_win);
		exit (0);
	}
	return (fr->iter);
}

int	handle_close(t_fractal *fr)
{
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->mlx_win);
	exit (0);
}

void	fractol_zoom_in(t_fractal *fr)
{
	double	zoom;
	double	center_r;
	double	center_i;

	zoom = 0.90;
	center_r = fr->min_r - fr->max_r;
	center_i = fr->max_i - fr->min_i;
	fr->max_r = fr->max_r + (center_r - zoom * center_r) / 2;
	fr->min_r = fr->max_r + zoom * center_r;
	fr->min_i = fr->min_i + (center_i - zoom * center_i) / 2;
	fr->max_i = fr->min_i + zoom * center_i;
	fr->render = 0;
}

void	fractol_zoom_out(t_fractal *fr)
{
	double	zoom;
	double	center_r;
	double	center_i;

	zoom = 1.10;
	center_r = fr->min_r - fr->max_r;
	center_i = fr->max_i - fr->min_i;
	fr->max_r = fr->max_r + (center_r - zoom * center_r) / 2;
	fr->min_r = fr->max_r + zoom * center_r;
	fr->min_i = fr->min_i + (center_i - zoom * center_i) / 2;
	fr->max_i = fr->min_i + zoom * center_i;
	fr->render = 0;
}
void	move(t_fractal *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}
void	put_mandelbrot(t_fractal *fr)
{
	int		is_fr;
	double	temp;

	fr->iter = 0;
	fr->zr = 0;
	fr->zi = 0;
	is_fr = 1;
	while (fr->iter++ < MAX_ITER)
	{
		if ((fr->zr * fr->zr + fr->zi * fr->zi) > 4)
		{
			is_fr = 0;
			break ;
		}
		temp = 2 * fr->zr * fr->zi + fr->ci;
		fr->zr = fr->zr * fr->zr - fr->zi * fr->zi + fr->cr;
		fr->zi = temp;
	}
	if (is_fr == 1)
		ft_pixel_put(fr, fr->x, fr->y, 0x00000000);
	if (is_fr == 0)
		put_color(fr);
}
void	draw_mandelbrot(t_fractal *fr)
{
	fr->y = -1;
	while (++fr->y < W)
	{
		fr->x = -1;
		while (++fr->x < W)
		{
			fr->cr = fr->min_r + (double)fr->x * ((fr->max_r - fr->min_r) / W);
			fr->ci = fr->min_i + (double)fr->y * ((fr->max_i - fr->min_i) / W);
			put_mandelbrot(fr);
		}
	}
}
void	put_julia(t_fractal *fr)
{
	int		is_fr;
	double	temp;

	fr->iter = 0;
	is_fr = 1;
	while (fr->iter++ < MAX_ITER)
	{
		if ((fr->zr * fr->zr + fr->zi * fr->zi) > 4)
		{
			is_fr = 0;
			break ;
		}
		temp = 2 * fr->zr * fr->zi + fr->ci;
		fr->zr = fr->zr * fr->zr - fr->zi * fr->zi + fr->cr;
		fr->zi = temp;
	}
	if (is_fr == 1)
		ft_pixel_put(fr, fr->x, fr->y, 0x00000000);
	if (is_fr == 0)
		put_color(fr);
}
void	draw_julia(t_fractal *fr)
{
	fr->y = -1;
	while (++fr->y < W)
	{
		fr->x = -1;
		while (++fr->x < W)
		{
			fr->zr = fr->min_r + (double)fr->x * ((fr->max_r - fr->min_r) / W);
			fr->zi = fr->min_i + (double)fr->y * ((fr->max_i - fr->min_i) / W);
			put_julia(fr);
		}
	}
}
int	render_fr(t_fractal *fr)
{
	if (fr->render == 0)
	{
		if (fr->what_fractol == 1)
			draw_mandelbrot(fr);
		if (fr->what_fractol == 0)
			draw_julia(fr);
		mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
		fr->render = 1;
	}
	return (fr->render);
}

int	handle_mouse(int button, int x, int y, t_fractal *fr)
{
	if (button == 1)
	{
		x -= W / 2;
		y -= W / 2;
		if (x < 0)
			move(fr, (double)x / W, 'R');
		else if (x > 0)
			move(fr, (double)x * -1 / W, 'L');
		if (y < 0)
			move(fr, (double)y * -1 / W, 'D');
		else if (y > 0)
			move (fr, (double)y / W, 'U');
		fr->render = 0;
	}
	if (button == 4)
		fractol_zoom_in(fr);
	if (button == 5)
		fractol_zoom_out(fr);
	return (fr->iter);
}

size_t	nbsize_atof(double n)
{
	size_t	i;
	int		x;

	x = (int)n;
	i = 0;
	if (x <= 0)
		i++;
	while (x != 0)
	{
		i++;
		x = x / 10;
	}
	return (i);
}

double	check_signal(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	else
		return (1);
}

double	my_atof(char *str)
{
	double	number;
	size_t	size;
	int		i;
	double	signal;
	double	p;

	i = 1;
	p = 1;
	signal = check_signal(str);
	number = (double)ft_atoi((const char *)str);
	if (signal < 0)
	{
		number = -number;
		i = 2;
	}
	size = nbsize_atof(number);
	while (str[size + i] >= '0' && str[size + i] <= '9')
	{
		number += (str[size + i] - 48) / pow(10, p);
		i++;
		p++;
	}
	return (number * signal);
}

int	ft_is_wrong_digit(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	if ((c >= 0 && c <= 44) || (c >= 58 && c <= 255))
		return (1);
	else
		return (0);
}

void	test_julia(char *argv1, char *argv2)
{
	int	i;

	i = -1;
	while (argv1[++i])
	{
		if (ft_is_wrong_digit(argv1[i]))
		{
			ft_putstr_fd("cr must be a real number.", 2);
			exit (0);
		}
	}
	i = -1;
	while (argv2[++i])
	{
		if (ft_is_wrong_digit(argv2[i]))
		{
			ft_putstr_fd("ci must be a real number.", 2);
			exit (0);
		}
	}
}

int	ft_errors(int argc, char *argv[])
{
	if (argc == 1 || argc == 3 || argc > 4)
	{
		ft_putstr_fd("Wrong arguments try:\nmandelbrot;\njulia, cr, ci;", 2);
		exit (0);
	}
	if (!ft_strcmp(argv[1], "mandelbrot") && argc == 2)
		return (1);
	if (!ft_strcmp(argv[1], "julia") && argc == 4)
	{
		test_julia(argv[2], argv[3]);
		return (2);
	}
	ft_putstr_fd("Wrong arguments try:\nmandelbrot;\njulia, cr, ci;", 2);
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (*str1 - *str2);
	while (i <= ft_strlen(s1) && i <= ft_strlen(s2))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractal fr;
	int			validate_args;

	validate_args = ft_errors(argc, argv);
	mlx_fractol(&fr);
	if (validate_args == 1)
		fr.what_fractol = 1;
	if (validate_args == 2)
	{
		fr.cr = my_atof(argv[2]);
		fr.ci = my_atof(argv[3]);
		fr.what_fractol = 0;
	}
	mlx_key_hook(fr.mlx_win, handle_keys, &fr);
	mlx_mouse_hook(fr.mlx_win, handle_mouse, &fr);
	mlx_hook(fr.mlx_win, 17, 0L, handle_close, &fr);
	mlx_loop_hook(fr.mlx, render_fr, &fr);
	mlx_loop(fr.mlx);
}
