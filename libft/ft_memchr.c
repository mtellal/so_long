/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:08:54 by mtellal           #+#    #+#             */
/*   Updated: 2021/01/07 11:05:51 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *tab;

	tab = s;
	while (n--)
	{
		if (*tab == (unsigned char)c)
		{
			return ((void *)tab);
		}
		tab++;
	}
	return (NULL);
}
