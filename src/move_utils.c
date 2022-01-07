/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:00:05 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 17:16:06 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_move(t_data *data, int m, int i, int j)
{
	if (m == UP && i > 0 && check_conditions(data, i - 1, j))
		return (1);
	if (m == DOWN && i < data->h && check_conditions(data, i + 1, j))
		return (1);
	if (m == LEFT && j > 0 && check_conditions(data, i, j - 1))
		return (1);
	if (m == RIGHT && j < data->w && check_conditions(data, i, j + 1))
		return (1);
	return (0);
}
