/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:50:28 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 17:15:09 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_consumn(t_data *data)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->tab[i][j] == 'C')
				a++;
			j++;
		}
		i++;
	}
	if (a)
		return (0);
	return (1);
}

int	check_conditions(t_data *data, int i, int j)
{
	if (data->tab[i][j] == 'E' && all_consumn(data))
		return (escape(data));
	if (data->tab[i][j] == '0' || data->tab[i][j] == 'C')
		return (1);
	return (0);
}

int	is_valid_move(int m, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->tab[i][j] == 'P')
			{
				if (valid_move(data, m, i, j))
					return (1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	move(int m, t_data *data)
{
	int	i;
	int	j;

	data->i = 0;
	while (data->i < data->h)
	{
		data->j = 0;
		while (data->j < data->w)
		{
			if (data->tab[data->i][data->j] == 'P')
			{
				if (m == UP)
					return (redraw(data, data->i - 1, data->j));
				if (m == DOWN)
					return (redraw(data, data->i + 1, data->j));
				if (m == LEFT)
					return (redraw(data, data->i, data->j - 1));
				if (m == RIGHT)
					return (redraw(data, data->i, data->j + 1));
			}
			data->j++;
		}
		data->i++;
	}
	return (0);
}	

int	move_player(int k, t_data *data)
{
	if (k == UP)
	{
		if (is_valid_move(UP, data))
			return (move(UP, data));
	}
	if (k == DOWN)
	{
		if (is_valid_move(DOWN, data))
			return (move(DOWN, data));
	}
	if (k == LEFT)
	{
		if (is_valid_move(LEFT, data))
			return (move(LEFT, data));
	}
	if (k == RIGHT)
	{
		if (is_valid_move(RIGHT, data))
			return (move(RIGHT, data));
	}
}
