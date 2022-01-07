/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:32:26 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 16:57:43 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_cube(t_data *data, int i, int j, int color)
{
	int		a;
	int		b;

	a = 0;
	while (a < data->sc)
	{
		b = 0;
		while (b < data->sc)
		{
			my_mlx_pixel_put(data, data->sc * j + a, b + i * data->sc, color);
			b++;
		}
		a++;
	}
}

int	redraw(t_data *data, int i, int j)
{
	int	s1;
	int	s2;

	data->move++;
	wich_element('P', data);
	data->tab[i][j] = 'P';
	data->tab[data->i][data->j] = '0';
	s1 = data->i;
	s2 = data->j;
	draw_image_to_image(data, i, j);
	reset_cube(data, s1, s2, 0x00000000);
	return (1);
}

int	draw_image_to_image(t_data *data, int a, int b)
{
	int		i;
	int		j;
	void	*p;

	i = 0;
	while (i < data->e.height)
	{
		j = 0;
		while (j < data->e.width)
		{
			data->i = i;
			data->j = j;
			p = data->e.addr + (i * data->e.ll + j * (data->e.bpp / 8));
			putpixel(data, a, b, p);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, data->e.img);
	return (1);
}

void	fill_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (wich_element(data->tab[i][j], data))
				draw_image_to_image(data, i, j);
			j++;
		}
		i++;
	}
}
