/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:28:26 by mtellal           #+#    #+#             */
/*   Updated: 2020/12/19 23:31:09 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *p;

	p = NULL;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s != '\0')
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if (p != NULL)
		return (p);
	return (NULL);
}
