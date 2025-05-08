/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:22:52 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/08 23:20:47 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_mandelbrot(t_fract *fractal, t_complex *c)
{
	double		temp;
	t_complex	z;
	int			i;

	i = -1;
	z.reel = 0;
	z.imagine = 0;
	while ((z.reel * z.reel + z.imagine * z.imagine) < 4 && ++i < fract->iterations)
	{
		temp = z.reel * z.reel - z.imagine * z.imagine + c->reel;
		z.imagine = 2 * z.reel * z.imagine + c->imagine;
		z.reel = temp;
	}
	return (i);
}

int	get_julia(t_fract *fractal, t_complex *c, int x, int y)
{
	double	temp;
	t_complex	z;
	int	i;

	i = -1;
	z.reel = (x / fractal->zoom) + fractal->offset_x;
	z.imagine = (y / fractal->zoom) + fractal->offset_y;
	while ((z.reel * z.reel - z.imagine * z.imagine) < 4 && ++i < fract->iterations)
	{
		temp = z.reel * z.reel - z.imagine * z.imagine + c->reel;
		z.imagine = 2 * z.reel * z.imagine + c->imagine;
		z.reel = temp;
	}
	return(i);
}
