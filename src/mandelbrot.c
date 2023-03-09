/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:40:55 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/09 15:23:02 by rthome-d         ###   ########.fr       */
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
