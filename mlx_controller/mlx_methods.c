/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:11:06 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/16 19:28:36 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

void	pallete_1(t_color *color)
{
	if (color->i == 0)
	{
		color->red = color->m;
		color->green = color->y;
		color->blue = color->c;
	}
	if (color->i == 1)
	{
		color->red = color->y;
		color->green = color->m;
		color->blue = color->c;
	}
	if (color->i == 2)
	{
		color->red = color->y;
		color->green = color->c;
		color->blue = color->m;
	}
}

void	pallete_2(t_color *color)
{
	if (color->i == 3)
	{
		color->red = color->y;
		color->green = color->c;
		color->blue = color->m;
	}
	if (color->i == 4)
	{
		color->red = color->m;
		color->green = color->y;
		color->blue = color->c;
	}
	if (color->i == 5)
	{
		color->red = color->c;
		color->green = color->y;
		color->blue = color->m;
	}
}
