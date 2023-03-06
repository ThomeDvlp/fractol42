/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:21 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/06 16:19:33 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mlx_controller(t_fractal *fr)
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