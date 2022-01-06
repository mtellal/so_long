/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:32:26 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/06 16:03:52 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    reset_cube(t_data *data, int i, int j, int color)
{
        int     a;
        int     b;

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

int     redraw(t_data *data, int i, int j, int a, int b, int color)
{
        data->move++;
	wich_element('P', data);
        data->tab[i][j] = 'P';
        data->tab[a][b] = '0';
        draw_image_to_image(data, i, j);
        reset_cube(data, a, b, color);
	return (1);
}


int	draw_image_to_image(t_data *data, int i, int j)
{
	int	a;
	int	b;
	void	*p;
	int	center;

	a = 0;
	center = (data->sc - data->e.width) / 2; 
	while (a < data->e.height)
	{
		b = 0;
		while (b < data->e.width)
		{
			p = data->e.addr + (a * data->e.ll + b * (data->e.bpp / 8));
			my_mlx_pixel_put(data,center + j * data->sc + b, center + i * data->sc + a, *(unsigned int*)p);
			b++;		
		}
		a++;
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
			if(wich_element(data->tab[i][j], data))					
				draw_image_to_image(data, i, j);
			j++;
		}
		i++;
	}
}
