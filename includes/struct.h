/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:16:45 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/05 15:30:26 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_H
#define _STRUCT_H


typedef	struct	s_img {
	void	*img;
	void	*addr;
	int	bpp;
	int	ll;
	int	endian;
	int	height;
	int	width;
}		t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int	h;
	int	w;
	char	**tab;
	int	sc;
	int	move;
	t_img	e;
	t_img	img;
}		t_data;

#endif

