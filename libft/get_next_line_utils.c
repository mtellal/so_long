/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:55:19 by mtellal           #+#    #+#             */
/*   Updated: 2021/12/29 17:46:50 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tab;
	char	*p;
	int		i;

	i = 0;
	if (!(tab = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	p = tab;
	while (s1 && *s1)
	{
		*tab++ = *s1++;
		i++;
	}
	free(s1 - i);
	i = 0;
	while (s2 && *s2)
	{
		*tab++ = *s2++;
		i++;
	}
	*tab = '\0';
	return (p);
}
