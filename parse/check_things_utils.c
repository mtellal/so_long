/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 23:08:55 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:03:23 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(int *e, int *p, int *c, int *i)
{
	*e = 0;
	*p = 0;
	*c = 0;
	*i = 0;
}

int	tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	point_ber(char *s)
{
	char	*ss;
	int		i;

	i = 0;
	ss = ft_strstr(s, ".ber");
	if (ss == s)
		return (0);
	while (ss && ss[i])
		i++;
	if (i != 4)
		return (0);
	return (1);
}

int	check_rectengular(char **tab)
{
	int		i;
	int		j;

	j = tab_len(tab);
	i = ft_strlen(*tab);
	if (i == j)
		return (0);
	return (1);
}

int	check_walls(char **tab, int i, int j)
{
	char	**c;

	c = tab;
	if (i == 0 && c[i][j] != '1')
		return (0);
	if (j == 0 && c[i][j] != '1')
		return (0);
	if (i == (tab_len(c) - 1) && c[i][j] != '1')
		return (0);
	if (j == (ft_strlen(c[i]) - 1) && c[i][j] != '1')
		return (0);
	return (1);
}
