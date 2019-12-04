/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:08:44 by mobouzar          #+#    #+#             */
/*   Updated: 2019/12/04 15:46:20 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		contains(t_lem_in *l, char *element)
{
	int	len;
	int	i;
	int m;
	
	i = 0;
	len = l->nbrooms - 1;
	while (i <= len)
	{
		m = (i + len) / 2;
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
	while (++i < l->nbrooms - 1)
	{
		j = -1;
		while (++j < l->nbrooms - i - 1)
			if (ft_strcmp(l->rooms[j], l->rooms[j + 1]) > 0)
			{
				len = ft_strlen(l->rooms[j]);
				if (!(tmp = (char *)malloc(sizeof(char) * len)))
					return ;
				ft_strcpy(tmp, l->rooms[j]);
				ft_strcpy(l->rooms[j], l->rooms[j + 1]);
				ft_strcpy(l->rooms[j + 1], tmp);
			}
	}
}

int		creat_rooms_array(t_lem_in *l, t_room *room)
{
	int	i;

	i = -1;
	if (!(l->rooms = (char **)malloc(sizeof(char *) * l->nbrooms)))
		return (0);
	while (room->next && ++i < l->nbrooms)
	{
		l->rooms[i] = room->name;
		room = room->next;
	}
	sort_rooms_array(l);
	return (1);
}
