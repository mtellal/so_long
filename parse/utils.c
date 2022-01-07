/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:49:16 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:56:18 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compare(int p, int c, int e)
{
	if (p != 1 || c < 0 || e < 0)
		return (0);
	return (1);
}

char	*err_char(char **tab)
{
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
