/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:30:48 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/13 21:57:22 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	kill_event(t_toscreen *screen)
{
	mlx_destroy_image(screen->mlx, screen->image.img_ptr);
	mlx_destroy_window(screen->mlx, screen->window);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	exit(0);
}

int	mousehook_event(int key, int x, int y, t_toscreen *screen)
{
	t_fract	*fr;

	fr = &screen->fract;
	if (key == 5)
	{
		fr->off_x = (x / fr->zoom + fr->off_x) - (x / (fr->zoom / 1.3));
		fr->off_y = (y / fr->zoom + fr->off_y) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
	}
	else if (key == 4)
	{
		fr->off_x = (x / fr->zoom + fr->off_x) - (x / (fr->zoom * 1.3));
		fr->off_y = (y / fr->zoom + fr->off_y) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
	}
	draw_fractal(screen);
	return (0);
}

int	keyhook_event(int key, t_toscreen *screen)
{
	if (key == 108 && screen->fract.type == 2)
		screen->fract.juliasearch ^= 1;
	if (key == 65307)
		kill_event(screen);
	return (0);
}

int	mousemove_event(int x, int y, t_toscreen *screen)
{
	if (screen->fract.type == 1 || screen->fract.juliasearch == 1)
		return (0);
	screen->fract.mouse_x = x;
	screen->fract.mouse_y = y;
	draw_fractal(screen);
	return (0);
}
/*
esc = 65307
l = 108
mouse scroll up = 4
mouse scroll down = 5
*/
