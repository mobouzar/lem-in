/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adj_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:20:23 by mobouzar          #+#    #+#             */
/*   Updated: 2019/12/05 01:53:58 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		ft_creat_adj(t_lem_in **lst, int nbrooms)
{
	if (!((*lst)->adlist = (t_queue **)malloc(sizeof(t_queue *) * nbrooms)))
		return (0);
	ft_memset((void *)(*lst)->adlist, '\0', sizeof(t_queue *) * nbrooms);
	return (1);
}

void	ft_add_node(t_lem_in **adj_list, int room_1, int room_2)
{
	t_queue		*tmp_1;
	t_queue		*tmp_2;
	t_queue		**lst;

	lst = (*adj_list)->adlist;
	if (!(tmp_1 = (t_queue *)malloc(sizeof(t_queue))))
		return ;
	if (!(tmp_2 = (t_queue *)malloc(sizeof(t_queue))))
		return ;
	tmp_1->node = room_1;
	tmp_1->next = NULL;
	tmp_2->node = room_2;
	tmp_2->next = NULL;
	if (lst[room_1])
		tmp_2->next = lst[room_1];
	lst[room_1] = tmp_2;
	if (lst[room_2])
		tmp_1->next = lst[room_2];
	lst[room_2] = tmp_1;
}

int		get_links(t_lem_in **l, char *line, char *start, char *end)
{
	char	**split;
	int		room1;
	int		room2;
	int		i;

	i = 0;
	room1 = -1;
	room2 = -1;
	split = ft_split_format(line, '-');
	while (split[i])
		i += 1;
	if (i != 2 || ((*l)->start == -1 || (*l)->end == -1))
	{
		ft_putendl("Error");
		exit(0);
	}
	if ((room1 = contains(*l, split[0], start, end)) != -1 &&
	(room2 = contains(*l, split[1], start, end)) != -1)
		ft_add_node(l, room1, room2);
	else
	{
		ft_putendl("link not found");
		exit(0);
	}
	return (1);
}
