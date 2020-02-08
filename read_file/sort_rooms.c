/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:08:44 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/08 11:21:45 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		ft_contains(t_lem_in *l, char *element)
{
	int	len;
	int	i;
	int m;
	
	i = 0;
	len = l->nbrooms - 1;
	while (i <= len)
	{
		m = (i + len) / 2;
		if (!ft_strcmp("l->rooms[m]", element))
			return (m);
		else if (ft_strcmp("l->rooms[m]", element) > 0)
			len = m - 1;
		else
			i = m + 1;
	}
	if (i > len)
		return (-1);
	return (m);
}

int		sort_rooms_array(t_lem_in *l)
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
				if (!(tmp = ft_strnew(len)))
					return (0);
				ft_strcpy(tmp, l->rooms[j]);
				ft_strcpy(l->rooms[j], l->rooms[i]);
				ft_strcpy(l->rooms[i], tmp);
				ft_strdel(&tmp);
			}
	}
	return (1);
}

int		creat_rooms_array(t_lem_in *l, t_room *room)
{
	t_room	*head;
	char	*start;
	char	*end;
	int		i;

	i = -1;
	head = room;
	if (!(l->rooms = (char **)malloc(sizeof(char *) * (l->nbrooms + 1))))
		return (0);
	ft_memset((void*)l->rooms, '\0', sizeof(l->rooms));
	while (++i < l->nbrooms && room && room->next)
	{
		if (i == l->start)
			start = ft_strdup(room->name);
		else if (i == l->end)
			end = ft_strdup(room->name);
		l->rooms[i] = ft_strdup(room->name);
		room = room->next;
	}
	sort_rooms_array(l);
	l->start = ft_contains(l, start);
	l->end = ft_contains(l, end);
	ft_strdel(&start);
	ft_strdel(&end);
	return (1);
}
