/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:59:14 by mtellal           #+#    #+#             */
/*   Updated: 2021/01/09 16:14:16 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		if (!(tab = (char *)malloc(sizeof(char))))
			return (NULL);
		*tab = '\0';
		return (tab);
	}
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(tab, (s + start), len + 1);
	return (tab);
}
