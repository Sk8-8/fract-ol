/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:07:05 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/08 02:30:48 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	how_to_use(void)
{
	ft_printf("type either 'm' or 'j' to proceed\n");
	ft_printf("whilst in the window press 'esc' or the 'X' icon to close it\n");
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
	if (argc != 2 || (checkerror(argv[1]) == 1))
		return (how_to_use());
	else
		return (ft_printf("oui\n"));
}
