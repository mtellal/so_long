/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:04:08 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:17:58 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	element(char *s, t_data *data)
{
	int	*h;
	int	*w;
	int	*ll;
	int	*bp;

	w = &data->e.width;
	h = &data->e.height;
	if (!s)
		return (0);
	data->e.img = mlx_xpm_file_to_image(data->mlx, s, w, h);
	ll = &data->e.ll;
	bp = &data->e.bpp;
	data->e.addr = mlx_get_data_addr(data->e.img, bp, ll, &data->e.endian);
	return (1);
}

int	wich_element(char e, t_data *data)
{
	if (e == '1')
		return (element("png/wall.xpm", data));
	if (e == '0')
		return (element(NULL, data));
	if (e == 'P')
		return (element("png/emoji.xpm", data));
	if (e == 'C')
		return (element("png/c.xpm", data));
	if (e == 'E')
		return (element("png/e.xpm", data));
	return (0);
}
