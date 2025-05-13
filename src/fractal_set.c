/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:22:52 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/14 00:54:21 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_mandelbrot(t_fract *fract, t_complex *c)
{
	double		temp;
	t_complex	z;
	int			i;

	i = -1;
	z.reel = 0;
	z.ima = 0;
	while ((z.reel * z.reel + z.ima * z.ima) < 4 && ++i < fract->iter)
	{
		temp = z.reel * z.reel - z.ima * z.ima + c->reel;
		z.ima = 2 * z.reel * z.ima + c->ima;
		z.reel = temp;
	}
	return (i);
}

int	get_julia(t_fract *fract, t_complex *c, int x, int y)
{
	double		temp;
	t_complex	z;
	int			i;

	i = -1;
	z.reel = (x / fract->zoom) + fract->off_x;
	z.ima = (y / fract->zoom) + fract->off_y;
	while ((z.reel * z.reel + z.ima * z.ima) < 4 && ++i < fract->iter)
	{
		temp = z.reel * z.reel - z.ima * z.ima + c->reel;
		z.ima = 2 * z.reel * z.ima + c->ima;
		z.reel = temp;
	}
	return (i);
}

int	calc_fractal(t_fract *fract, t_complex *c, int x, int y)
{
	int	iter;

	iter = 0;
	if (fract->type == 1)
	{
		c->ima = (y / fract->zoom) + fract->off_y;
		iter = get_mandelbrot(fract, c);
	}
	else
	{
		if (fract->juliasearch == 0)
			c->ima = (fract->mouse_y / fract->zoom) + fract->off_y;
		iter = get_julia(fract, c, x, y);
	}
	return (iter);
}

void	set_pixel_color(t_toscreen *screen, int x, int y, int color)
{
	int	line_len;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= 800 || y < 0 || y >= 800)
		return ;
	line_len = screen->image.line_len;
	pixel_bits = screen->image.pixel_bits;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	*(unsigned int *)(screen->image.addr_ptr + offset) = color;
}

void	draw_fractal(t_toscreen *screen)
{
	static t_complex	c;
	t_fract				*fract;
	int					iter;
	int					x;
	int					y;

	x = -1;
	fract = &screen->fract;
	mlx_clear_window(screen->mlx, screen->window);
	while (++x < 800)
	{
		y = -1;
		if (fract->type == 1)
			c.reel = (x / fract->zoom) + fract->off_x;
		else if (!fract->juliasearch)
			c.reel = (fract->mouse_x / fract->zoom) + fract->off_x;
		while (++y < 800)
		{
			iter = calc_fractal(fract, &c, x, y);
			set_pixel_color(screen, x, y, (iter * 8 * fract->color));
		}
	}
	mlx_put_image_to_window(screen->mlx, screen->window, \
							screen->image.img_ptr, 0, 0);
}
