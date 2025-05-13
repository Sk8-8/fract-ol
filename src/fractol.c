/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:07:05 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/13 22:31:59 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	how_to_use(void)
{
	ft_printf("type either 'm' or 'j' to proceed\n");
	ft_printf("the scroll wheel allows you to zoom in or out the set\n");
	ft_printf("in the julia set, your mouse position change the set\n");
	ft_printf("pressing the 'L' key locks the set to allow you to explore\n");
	ft_printf("whilst in the window press 'esc' or the 'X' icon to close\n\n");
	ft_printf("thank you !\n");
	return (1);
}

int	checkerror(char *type)
{
	if (ft_strlen(type) != 1)
		return (1);
	if (type[0] == 'j')
		return (0);
	if (type[0] == 'm')
		return (0);
	else
		return (1);
}

void	fill_screen(t_toscreen *screen, int set_type)
{
	screen->fract.type = set_type;
	screen->fract.zoom = 800 / 4;
	screen->fract.mouse_x = 0;
	screen->fract.mouse_y = 0;
	screen->fract.off_x = -2;
	screen->fract.off_y = -2;
	screen->fract.juliasearch = 1;
	screen->fract.color = 165;
	screen->fract.iter = 50;
}

void	init_screen(t_toscreen *screen)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	screen->mlx = mlx_init();
	screen->window = mlx_new_window(screen->mlx, 800, 800, "Fractol");
	screen->image.img_ptr = mlx_new_image(screen->mlx, 800, 800);
	screen->image.addr_ptr = mlx_get_data_addr(screen->image.img_ptr, \
								&pixel_bits, &line_len, &endian);
	screen->image.pixel_bits = pixel_bits;
	screen->image.line_len = line_len;
	screen->image.endian = endian;
}

int	main(int argc, char **argv)
{
	t_toscreen	screen;

	if (argc != 2 || (checkerror(argv[1]) == 1))
		return (how_to_use());
	if (argv[1][0] == 'm')
		fill_screen(&screen, 1);
	else
		fill_screen(&screen, 2);
	init_screen(&screen);
	draw_fractal(&screen);
	mlx_key_hook(screen.window, keyhook_event, &screen);
	mlx_mouse_hook(screen.window, mousehook_event, &screen);
	mlx_hook(screen.window, 6, 1L << 6, mousemove_event, &screen);
	mlx_hook(screen.window, 17, 0, kill_event, &screen);
	mlx_loop(screen.mlx);
	return (0);
}
