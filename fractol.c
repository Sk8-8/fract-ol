/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:07:05 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/10 03:46:59 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	how_to_use(void)
{
	ft_printf("type either 'm' or 'j' to proceed\n");
	ft_printf("the scroll wheel allows you to zoom in or out the selected set\n");
	ft_printf("in the julia set, your mouse position will change the set\n");
	ft_printf("pressing the 'L' key locks the set to allow you to explore it\n");
	ft_printf("whilst in the window press 'esc' or the 'X' icon to close it\n\n");
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

int	main(int argc, char **argv)
{
	t_toscreen	screen;

	if (argc != 2 || (checkerror(argv[1]) == 1))
		return (how_to_use());
	if (argv[1][0] == 'm')
		screen->fractal.type = 1;
	else
		screen->fractal.type = 2;
	init_screen(&screen);
	draw_fractal(&screen);
	mlx_key_hook(screen.window, keyhook_event, &screen);
	mlx_mouse_hook(screen.window, mousehook_event, &screen);
	mlx_hook(screen.window, 6, 1L << 6, mousemove_event, &screen);
	mlx_hook(screen.window, 17, 0, kill_event, &screen);
	mlx_loop(screen.mlx);
	return (0);
}
