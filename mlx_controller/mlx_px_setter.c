/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_px_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:18:01 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/16 20:07:28 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

void	hsv_to_rgb(t_color *color)
{
	if (color->s == 0)
	{
		color->r = color->h;
		color->g = color->h;
		color->b = color->h;
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
	color->y = color->v * (1.0 - color->s);
	color->c = color->v * (1.0 - (color->s * color->f));
	color->m = color->v * (1.0 - (color->s * (1.5 - color->f)));
	pallete_1(color);
	pallete_2(color);
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

	color.h = 133 * fr->iter;
	color.s = 0.6;
	color.v = 0.6;
	while (color.h > 360)
		color.h = color.h - 360;
	hsv_to_rgb(&color);
	ft_rgb(&color);
	ft_pixel_put(fr, fr->x, fr->y, color.rgb);
}
