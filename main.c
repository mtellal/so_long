/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:59:27 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:00:01 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	errno = 0;
	if (argc == 2)
	{
		map_all(argv[1], &data);
		data.move = 0;
		data.sc = 70;
		data.w = ft_strlen(data.tab[0]);
		data.h = tab_len(data.tab);
		game(&data);
	}
	else
	{
		print_err("invalid args", 0);
	}
	return (0);
}
