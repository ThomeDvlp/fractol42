/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:21 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/16 20:08:00 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mlx_controller(t_fractal *fr)
{
	fr->min_r = -2;
	fr->max_r = 2;
	fr->min_i = -1.5;
	fr->max_i = fr->min_i + (fr->max_r - fr->min_r) * ((double)H / (double)W);
	fr->render = 0;
	fr->mlx = mlx_init();
	fr->mlx_win = mlx_new_window(fr->mlx, H, W, "Fractol");
	fr->img = mlx_new_image(fr->mlx, H, W);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits, &fr->line, &fr->endian);
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

int	handle_mouse(int button, int x, int y, t_fractal *fr)
{
	if (button == 1)
	{
		x -= W / 2;
		y -= H / 2;
		if (x < 0)
			move(fr, (double)x / H, 'R');
		else if (x > 0)
			move(fr, (double)x * -1 / H, 'L');
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

int	handle_close(t_fractal *fr)
{
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->mlx_win);
	exit (0);
}
