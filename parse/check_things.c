/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:34:23 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/05 18:37:17 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_proportionate(char **tab)
{
	int	a;

	a = ft_strlen(*tab);
	while (*tab)
	{
		if (a != ft_strlen(*tab))
			return (0);
		tab++;
	}
	return (1);

}

int	check_atleast(char **tab)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	init_var(&e, &p, &c, &i, &j);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
				p++;
			if (tab[i][j] == 'C')
				c++;
			if (tab[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || c < 0 || e < 0)
		return (0);
	return (1);
}

char	*check_map(char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (!tab || !*tab)
		return ("fichier vide");
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!check_walls(tab, i, j))
				return ("probleme de mur bg");
			j++;
		}
		i++;
	}
	if (!check_proportionate(tab))
	       return ("probleme de longueur");
	if (!check_atleast(tab))
		return ("manque un element (E, C, P) ou 2 Player");
	if (!check_rectengular(tab))
		return ("t'as fait un carre wsh");
	if (!check_bad_items(tab))
		return ("char inconnu diff de (10EPC)");
	return (0);
}

char	*check_file(char *s, int *f)
{
	int	fd;

	 if (!point_ber(s))
                print_err("nom de fichier invalide (.ber)", 0);
        fd = open(s, O_RDONLY);
        if (fd == -1)
        {
		print_err("impossible d'ouvrir le fichier", 1);
		close(fd);
	}
	*f = fd;
	return (0);
}

void	map_all(char *s, t_data *data)
{
	char	**tab;
	t_list	*lst;
	char	*err;
	int	fd;

	err = check_file(s, &fd);
	lst = map_to_list(fd);
	tab = list_to_tab(lst);
	data->tab = tab;
	data->w = ft_strlen(data->tab[0]);
        data->h = tab_len(data->tab);
	err = check_map(tab);
	if (err)
	{
		free_tab(data);
		print_err(err, 0);
	}
}
