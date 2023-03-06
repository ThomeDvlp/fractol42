/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:55:17 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/06 16:36:47 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

double	fract_atoi(char *str)
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
	mlx_controller(&fr);
	if (validate_args == 1)
		fr.what_fractol = 1;
	if (validate_args == 2)
	{
		fr.cr = fract_atoi(argv[2]);
		fr.ci = fract_atoi(argv[3]);
		fr.what_fractol = 0;
	}
	mlx_key_hook(fr.mlx_win, handle_keys, &fr);
	mlx_mouse_hook(fr.mlx_win, handle_mouse, &fr);
	mlx_hook(fr.mlx_win, 17, 0L, handle_close, &fr);
	mlx_loop_hook(fr.mlx, render_fr, &fr);
	mlx_loop(fr.mlx);
}
