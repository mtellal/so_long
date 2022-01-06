/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:34:01 by mtellal           #+#    #+#             */
/*   Updated: 2021/01/14 10:48:44 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_belong(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s, char const *set)
{
	char			*tab;
	int				i;
	char const		*r;

	i = 0;
	r = s;
	if (s == NULL)
		return (NULL);
	while (ft_belong(s[i], set) && s[i])
		i++;
	s = r + ft_strlen(r) - 1;
	while (ft_belong(*s, set) && *s--)
		i++;
	if (i == (int)(2 * ft_strlen(r)))
		i = ft_strlen(r) - 1;
	if (!(tab = (char*)malloc(sizeof(char) * (ft_strlen(r) - i) + 1)))
		return (NULL);
	i = ft_strlen(r) - i;
	tab[i--] = '\0';
	while (i >= 0)
		tab[i--] = *s--;
	return (tab);
}
