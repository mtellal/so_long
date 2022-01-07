/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:15:07 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:19:19 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	escape(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	free_tab(data);
	mlx_loop_end(data->mlx);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	no_event(t_data *data)
{
	ft_putstr_fd("nombre de moove: ", 1);
	ft_putnbr_fd(data->move, 1);
	ft_putstr_fd(" \r", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	key_press(int k, t_data *data)
{
	if (k == ESCP)
		return (escape(data));
	if (k == UP || k == DOWN || k == LEFT || k == RIGHT)
		return (move_player(k, data));
}
