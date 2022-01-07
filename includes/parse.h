/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:30:35 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 15:54:09 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int			check_walls(char **tab, int i, int j);
t_list		*map_to_list(int fd);
int			strlen_tab(char **tab);
char		**list_to_tab(t_list *lst);
char		*check_map(char **tab);
void		map_all(char *path, t_data *data);
void		init_var(int *e, int *p, int *c, int *i);
int			check_rectengular(char **tab);
int			tab_len(char **t);
int			point_ber(char *s);
int			check_bad_items(char **tab);
int			compare(int p, int c, int e);
char		*err_char(char **tab);
int			check_proportionate(char **tab);
int			check_atleast(char **tab);

#endif
