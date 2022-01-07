/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:47:16 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:08:22 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	belong(char c)
{
	char	*s;

	s = "CEP10";
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	check_bad_items(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!belong(tab[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_list	*map_to_list(int fd)
{
	char	*line;
	t_list	*tab;

	tab = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&tab, ft_lstnew(ft_strdup(line)));
		free(line);
		line = NULL;
	}
	free(line);
	close(fd);
	return (tab);
}

void	delete(void *p)
{
	free(p);
}

char	**list_to_tab(t_list *lst)
{
	char	**tab;
	int		i;
	char	*e;
	int		j;
	t_list	*l1;

	j = 0;
	l1 = lst;
	i = ft_lstsize(lst);
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	while (lst)
	{
		tab[j++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	tab[j] = 0;
	ft_lstclear(&l1, delete);
	return (tab);
}
