/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:55:17 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/16 20:14:11 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	render_fr(t_fractal *fr)
{
	if (fr->render == 0)
	{
		if (fr->fractal == 1)
			draw_mandelbrot(fr);
		if (fr->fractal == 0)
			draw_julia(fr);
		mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
		fr->render = 1;
	}
	return (fr->render);
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

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
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
	t_fractal	fr;
	int			validate_args;

	validate_args = ft_errors(argc, argv);
	mlx_controller(&fr);
	if (validate_args == 1)
		fr.fractal = 1;
	if (validate_args == 2)
	{
		fr.cr = fracatoi(argv[2]);
		fr.ci = fracatoi(argv[3]);
		fr.fractal = 0;
	}
	mlx_key_hook(fr.mlx_win, handle_keys, &fr);
	mlx_mouse_hook(fr.mlx_win, handle_mouse, &fr);
	mlx_hook(fr.mlx_win, 17, 0L, handle_close, &fr);
	mlx_loop_hook(fr.mlx, render_fr, &fr);
	mlx_loop(fr.mlx);
}
