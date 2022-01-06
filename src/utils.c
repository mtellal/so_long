/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:42:42 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/06 15:53:45 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->h)
		free(data->tab[i++]);
	free(data->tab);
}

void	print_err(char *err, int i)
{
	if (i)
		perror("Error");
	else
		ft_putendl_fd("Error", 1);
	ft_putendl_fd(err, 1);
	exit(0);
}
