/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 02:31:09 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/08 22:22:20 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include <math.h>

typedef struct s_pixel
{
	int	x;
	int	y;
	t_pixel;
}

typedef struct s_complex
{
	double	reel;
	double	imagine;
} t_complex;

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
	int	type;
	double	zoom;
	u_int32_t	color;
	double	mouse_x;
	double	mouse_y;
	double	offset_x;
	double	offset_y;
	int		iterations;
	int		juliasearch;
}	t_fract

typedef struct s_toscreen
{
	void	*mlx;
	void	*window;
	t_image	image;
	t_fract	fractal;
} t_toscreen;

int	get_mandelbrot(t_fract *fractal, t_complex *c);
int	get_julia(t_fract *fractal, t_complex *c, int x, int y);

#endif
