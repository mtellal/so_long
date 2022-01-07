/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:11:43 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 17:23:55 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "stdlib.h"
# include <errno.h>

# include "libft.h"
# include "struct.h"
# include "parse.h"

# define ESCP 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

void		free_tab(t_data *data);
void		print_err(char *err, int i);
void		game(t_data *data);
int			no_event( t_data *data);
int			key_press(int k, t_data *data);
void		fill_window(t_data *data);
int			wich_element(char c, t_data *data);
void		my_mlx_pixel_put(t_data *data, int i, int j, int color);
int			escape(t_data *data);
int			move_player(int k, t_data *data);
int			draw_image_to_image(t_data *data, int i, int j);
int			wich_element(char c, t_data *data);
void		reset_cube(t_data *data, int i, int j, int color);
int			redraw(t_data *data, int i, int j);
void		putpixel(t_data *data, int i, int j, void *p);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			valid_move(t_data *data, int m, int i, int j);
int			check_conditions(t_data *data, int i, int j);

#endif
