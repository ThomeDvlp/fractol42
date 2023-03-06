/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:18:01 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/06 16:31:23 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bits / 8));
	*(unsigned int*)dst = color;
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