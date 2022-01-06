/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upgrade_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:47:58 by mtellal           #+#    #+#             */
/*   Updated: 2021/12/28 19:52:40 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_upgrade_tab(void **tab, void *e)
{
	void	**t;
	int	i;

	i = ft_strlen(tab);
	t = (void**)malloc(sizeof(void*) * i  + 2);
	if (!t)
		return (NULL); 
	while(i > 0)
	{
		*t = *tab;
		t++;
		tab++;
		i--;
	}
	*t++ = e;
	*t = NULL;
	return (t);
}
