/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:00:06 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 16:56:09 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putpixel(t_data *data, int a, int b, void *p)
{
	int	sc;
	int	c;
	int	i;
	int	j;

	sc = data->sc;
	c = (sc - data->e.width) / 2;
	i = data->i;
	j = data->j;
	my_mlx_pixel_put(data, c + b * sc + j, c + a * sc + i, *(unsigned int *)p);
}
