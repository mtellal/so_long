/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:02:43 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:23:19 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data)
{
	int	sc;
	int	h;
	int	*bpp;
	int	*e;

	h = data->h;
	sc = data->sc;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w * sc, h * sc, "./so_long");
	data->img.img = mlx_new_image(data->mlx, data->w * sc, h * sc);
	bpp = &data->img.bpp;
	e = &data->img.endian;
	data->img.addr = mlx_get_data_addr(data->img.img, bpp, &data->img.ll, e);
	fill_window(data);
}

void	game(t_data *data)
{
	errno = 0;
	init(data);
	mlx_hook(data->win, 33, 1L << 17, &escape, data);
	mlx_loop_hook(data->mlx, &no_event, data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_loop(data->mlx);
}
