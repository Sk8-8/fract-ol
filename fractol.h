/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 02:31:09 by kguillem          #+#    #+#             */
/*   Updated: 2025/05/08 02:40:12 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
}	t_image;
