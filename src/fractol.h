/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 02:31:09 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/14 00:55:17 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "../minlib/mlx.h"

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	reel;
	double	ima;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fract
{
	int			type;
	double		zoom;
	u_int32_t	color;
	double		mouse_x;
	double		mouse_y;
	double		off_x;
	double		off_y;
	int			iter;
	int			juliasearch;
}	t_fract;

typedef struct s_toscreen
{
	void	*mlx;
	void	*window;
	t_image	image;
	t_fract	fract;
}	t_toscreen;

int		get_mandelbrot(t_fract *fract, t_complex *c);
int		get_julia(t_fract *fract, t_complex *c, int x, int y);
int		calc_fractal(t_fract *fract, t_complex *c, int x, int y);
int		kill_event(t_toscreen *screen);
int		mousehook_event(int key, int x, int y, t_toscreen *screen);
int		keyhook_event(int key, t_toscreen *screen);
int		mousemove_event(int x, int y, t_toscreen *screen);
int		how_to_use(void);
int		checkerror(char *type);
int		main(int argc, char **argv);
void	set_pixel_color(t_toscreen *screen, int x, int y, int color);
void	draw_fractal(t_toscreen *screen);
void	fill_screen(t_toscreen *screen, int set_type);
void	init_screen(t_toscreen *screen);
#endif
