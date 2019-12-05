/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:08:44 by mobouzar          #+#    #+#             */
/*   Updated: 2019/12/05 16:58:36 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		contains(t_lem_in *l, char *element, char *start, char *end)
{
	int	len;
	int	i;
	int m;
	
	i = 0;
	len = l->nbrooms - 1;
	while (i <= len)
	{
		m = (i + len) / 2;
		if (ft_strstr(l->rooms[m], start))
			l->start = m;
		else if (ft_strstr(l->rooms[m], end))
			l->end = m;
		if (!ft_strcmp(l->rooms[m], element))
			return (m);
		else if (ft_strcmp(l->rooms[m], element) > 0)
			len = m - 1;
		else
			i = m + 1;
	}
	if (i > len)
		return (-1);
	return (m);
}

void	sort_rooms_array(t_lem_in *l)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	i = -1;
	tmp = NULL;
	while (++i < l->nbrooms)
	{
		j = -1;
		while (++j < l->nbrooms)
			if (ft_strcmp(l->rooms[j], l->rooms[i]) > 0)
			{
				len = ft_strlen(l->rooms[j]);
				if (!(tmp = (char *)malloc(sizeof(char) * len)))
					return ;
				ft_strcpy(tmp, l->rooms[j]);
				ft_strcpy(l->rooms[j], l->rooms[i]);
				ft_strcpy(l->rooms[i], tmp);
				ft_strdel(&tmp);
			}
	}
}

int		creat_rooms_array(t_lem_in *l, t_room *room, char **start, char **end)
{
	int		i;

	i = -1;
	if (!(l->rooms = (char **)malloc(sizeof(char *) * l->nbrooms)))
		return (0);
	while (room->next && ++i < l->nbrooms)
	{
		if (i == l->start)
			*start = ft_strdup(room->name);
		else if (i == l->end)
			*end = ft_strdup(room->name);
		l->rooms[i] = room->name;
		room = room->next;
	}
	sort_rooms_array(l);
	// i = -1;
	// while (++i < l->nbrooms)
	// 	ft_printf("%s\n", l->rooms[i]);
	return (1);
}
