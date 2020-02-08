/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/08 11:04:19 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

// void		ft_print_adj(t_lem_in *adj)
// {
// 	t_queue	*queue;
// 	t_queue	**lst;
// 	int		i;

// 	i = -1;
// 	queue = NULL;
// 	printf("s = %d	end = %d		s = %s		e =%s\n",adj->start, adj->end,adj->rooms[adj->start], adj->rooms[adj->end]);
// 	lst = adj->adlist;
// 	while (++i < adj->nbrooms)
// 	{
// 		queue = lst[i];
// 		ft_printf("index -> %d = ", i);
// 		while (queue != NULL)
// 		{
// 			ft_printf("%d -> ", queue->node);
// 			queue = queue->next;
// 		}
// 		ft_putchar('\n');
// 	}
// }

static int	ft_free_split(char **split, int ret)
{
	int	i;
	
	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	free(split);
	return (ret);
}

static int	is_valid(char *line, char del)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != del)
		i += 1;
	if (line[i] != del || line[0] == 'L' || line[0] == '#')
		return (0);
	return (1);
}

static int	ft_free_data(t_room *room, char *line)
{
	ft_free_room(&room);
	ft_strdel(&line);
	return (0);
}

int			read_data(t_map *map, t_lem_in *l)
{
	t_room	*room;
	t_room	*head;
	char	*line;
	int		i;

	i = 0;
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	ft_memset(room, 0, sizeof(t_room));
	head = room;
	while (get_next_line(0, &line) == 1)
	{
		if (i == 0 && (l->type = get_nbants(l, line)) && (i = 1))
		{
			if (l->type == -1)
				return (ft_free_data(head, line));
			map->data = ft_strdup(line);
		}
		else if (line[0] == '#' && line[1] == '#')
		{
			map->data = ft_strdup(line);
			if ((i == 1 || i == 2) &&
			(!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end")) && (i++))
			{
				ft_strdel(&line);
				if (get_next_line(0, &line) != 1)
					return (ft_free_data(head, line));
				if (!is_valid(line, ' ') && (l->start != -1 || l->end != -1))
					return (ft_free_data(head, line));
				if (!get_rooms(l, &room, &map, line))
					return (ft_free_data(head, line));
				ft_strdel(&line);
			}
		}
		else if (l->type != LINK && is_valid(line, ' ') && check_room(&room, line))
		{
			map->data = ft_strdup(line);
			l->nbrooms += 1;
		}
		else if (line[0] == '#' && line[1] != '#')
			map->data = ft_strdup(line);
		else if (is_valid(line, '-'))
		{
			if (i == 3 && l->start >= 0 && l->end >= 0 && (i = 4))
				if (!creat_rooms_array(l, head) || !ft_creat_adj(&l, l->nbrooms))
					return (ft_free_data(head, line));
			if (!get_links(&l, line))
				return (ft_free_data(head, line));
			map->data = ft_strdup(line);
			l->type = LINK;
		}
		else
			return (ft_free_data(head, line));
		if (!(map->next = (t_map *)malloc(sizeof(t_map))))
			return (ft_free_data(head, line));
		ft_memset((void*)map->next, 0, sizeof(t_map));
		map = map->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_free_room(&head);
	if (!l->adlist)
		return (0);
	return (1);
}

int		get_links(t_lem_in **l, char *line)
{
	char	**split;
	int		room1;
	int		room2;
	int		i;

	i = 0;
	room1 = -1;
	room2 = -1;
	if (!(split = ft_split_format(line, '-')))
		return (0);
	while (split[i])
		i += 1;
	if (i != 2 || ((*l)->start == -1 || (*l)->end == -1))
		return (ft_free_split(split, 0));
	if ((room1 = ft_contains(*l, split[0])) != -1 &&
	(room2 = ft_contains(*l, split[1])) != -1)
	{
		if (!ft_add_node(l, room1, room2))
			return (ft_free_split(split, 0));
	}
	else
		return (ft_free_split(split, 0));
	return (ft_free_split(split, 1));
}

int		get_nbants(t_lem_in *l, char *line)
{
	int		len;
	int		i;

	i = 0;
	l->nbants = -1;
	if (line[0] == '#' && line[1] != '#')
		return (0);
	len = ft_strlen(line);
	while (len <= 10 && line[i])
		if (ft_isdigit(line[i]))
			i++;
		else
			return (-1);
	if (len <= 10)
		l->nbants = ft_atoi(line);
	if (l->nbants == 0 || len > 10)
		return (-1);
	return (1);
}

static int	is_cord(char *nbr)
{
	int	i;

	i = -1;
	while (nbr[++i])
	{
		if (i == 0 && (nbr[i] == '-' || nbr[i] == '+'))
			i++;
		if (!ft_isdigit(nbr[i]))
			return (0);
	}
	return (1);
}

int			check_room(t_room **r, char *line)
{
	char	**split;
	int		ret;
	int		i;

	i = -1;
	ret = 1;
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	if (!((*r)->next = (t_room *)malloc(sizeof(t_room))))
		return (0);
	ft_memset((void*)(*r)->next, 0, sizeof(t_room));
	if (!(split = ft_split_format(line, ' ')))
		return (0);
	while (split[++i] != NULL)
		if (i == 0)
			(*r)->name = ft_strdup(split[i]);
		// else if (i == 1)
		// 	(*r)->cords.x = ft_atoi(split[i]);
		// else if (i == 2)
		// 	(*r)->cords.y = ft_atoi(split[i]);
	if (i != 3)
		return (ft_free_split(split, 0));
	if (!is_cord(split[1]) || !is_cord(split[2]))
		return (ft_free_split(split, 0));
	(*r) = (*r)->next;
	return (ft_free_split(split, 1));
}

int		get_rooms(t_lem_in *l, t_room **a, t_map **map, char *line)
{
	if (!ft_strcmp((*map)->data, "##start"))
	{
		if (!check_room(a, line))
			return (0);
		if (!((*map)->next = (t_map *)malloc(sizeof(t_map))))
			return (0);
		ft_memset((void*)(*map)->next, 0, sizeof(t_map));
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		l->start = l->nbrooms;
		l->nbrooms += 1;
	}
	else if (!ft_strcmp((*map)->data, "##end"))
	{
		if (!check_room(a, line))
			return (0);
		if (!((*map)->next = (t_map *)malloc(sizeof(t_map))))
			return (0);
		ft_memset((void*)(*map)->next, 0, sizeof(t_map));
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		l->end = l->nbrooms;
		l->nbrooms += 1;
	}
	return (1);
}
