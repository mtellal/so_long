/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:08:05 by mtellal           #+#    #+#             */
/*   Updated: 2020/12/21 17:07:59 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!aiguille[0])
		return ((char*)meule_de_foin);
	while (meule_de_foin[i] && i < n)
	{
		if (meule_de_foin[i + j] == aiguille[j])
		{
			while (meule_de_foin[i + j] == aiguille[j]
					&& i + j < n && aiguille[j])
				j++;
			if (aiguille[j] == '\0')
				return ((char *)&meule_de_foin[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
