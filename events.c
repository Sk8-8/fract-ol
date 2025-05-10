/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:30:48 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/09 18:06:48 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_fract	*frac;

	frac = &screen->fract;
	if (key == )
	{
		frac->offset_x = (x / fr->zoom + frac->offset_x) - (x / (frac->zoom / 1.3));
		frac->offset_y = (y / fr->zoom + frac->offset_y) - (y / (frac->zoom / 1.3));
		frac->zoom /= 1.3;
	}
	else if (key ==)
	{
		frac->offset_x = (x / fr->zoom + frac->offset_x) - (x / (frac->zoom * 1.3));
		frac->offset_y = (y / fr->zoom + frac->offset_y) - (y / (frac->zoom * 1.3));
		frac->zoom *= 1.3;
	}
	draw_fractal(screen);
	return (0)
}

int	keyhook_event(int key, t_toscreen *screen)
{
	if (key ==)
		kill_event(screen);
	return (0);
}

int	mousemove_event(int x, int y, t_toscreen *screen)
{
	if (screen->fractal.type == 1 || screen->fractal.juliasearch == 1)
		return (0);
	screen->fractal.mouse_x = x;
	screen->fractal.mouse_y = y;
	draw_fractal(screen);
	return (0);
}
