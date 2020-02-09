/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/09 07:31:37 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int ft_free_split(char **split, int ret)
{
	int i;

	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	ft_memdel((void *)&split);
	return (ret);
}

static int is_valid(char *line, char del)
{
	int i;

	i = 0;
	while (line[i] && line[i] != del)
		i += 1;
	if (line[i] != del || line[0] == 'L' || line[0] == '#')
		return (0);
	return (1);
}

static int ft_free_data(t_room *room, char *line)
{
	ft_free_room(&room);
	ft_strdel(&line);
	return (0);
}

int get_command(t_lem_in *l, t_map *map, t_room *room, char *line)
{
	if (((l)->bool == 1 || (l)->bool == 2) &&
		(!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end")) && ((l)->bool ++))
	{
		ft_strdel(&line);
		if (get_next_line(0, &line) == -1)
			return (0);
		if (!is_valid(line, ' ') && ((l)->start != -1 || (l)->end != -1))
			return (0);
		if (!get_rooms(l, &room, &map, line))
			return (0);
		ft_strdel(&line);
	}
	return (1);
}

int helper_func(t_lem_in *l, t_map *map, t_room *room, char *line)
{
	if (line[0] == '#' && line[1] == '#')
	{
		map->data = ft_strdup(line);
		if ((l->bool == 1 || l->bool == 2) &&
			(!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end")) && (l->bool ++))
		{
			ft_strdel(&line);
			if (get_next_line(0, &line) != 1)
				return (0);
			if (!is_valid(line, ' ') && (l->start != -1 || l->end != -1))
				return (0);
			if (!get_rooms(l, &room, &map, line))
				return (0);
			ft_strdel(&line);
		}
	}
	else if (line && l->type != LINK && is_valid(line, ' ') && check_room(&room, line))
	{
		map->data = ft_strdup(line);
		l->nbrooms += 1;
	}
	else if (line && line[0] == '#' && line[1] != '#')
		map->data = ft_strdup(line);
	return (1);
}

int check_link(t_lem_in *l, t_map *map, t_room *room, char *line)
{
	int i;

	i = 0;
	if (l->bool == 3 && l->start >= 0 && l->end >= 0 && (l->bool = 4))
		if (!creat_rooms_array(l, room) || !ft_creat_adj(&l, l->nbrooms))
			return (0);
	if (!get_links(&l, line))
		return (0);
	map->data = ft_strdup(line);
	l->type = LINK;
	return (1);
}

int tarf_lawal(t_map **map, t_lem_in *l, t_room **room, char *line)
{
	char *tmp;
	
	tmp = NULL;
	if (l->bool == 0 && (l->type = get_nbants(l, line)) && (l->bool = 1))
	{
		if (l->type == -1)
			return (0);
		(*map)->data = ft_strdup(line);
		return(1);
	}
	else if (line[0] == '#' && line[1] == '#')
	{
		(*map)->data = ft_strdup(line);
		if ((l->bool == 1 || l->bool == 2) &&
			(!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end")) && (l->bool++))
		{
			if ((get_next_line(0, &tmp) != 1) ||
					(!is_valid(tmp, ' ') && (l->start != -1 || l->end != -1)) ||
												(!get_rooms(l, room, map, tmp)))
				return (0);
			ft_strdel(&tmp);
		}
		return(1);
	}
	return(-1);
}

t_room *tarf_lakhar(t_map *map, t_lem_in *l, t_room **room, char *line)
{
	if (l->type != LINK && is_valid(line, ' ') && check_room(&room[1], line))
	{
		l->nbrooms++;
		map->data = ft_strdup(line);
	}
	else if (line && line[0] == '#' && line[1] != '#')
		map->data = ft_strdup(line);
	else if (is_valid(line, '-'))
	{
		if (line && !check_link(l, map, *room, line))
			return (NULL);
	}
	else
		return (NULL);
	return (room[1]);
}

int read_data(t_map *map, t_lem_in *l)
{
	t_room *room;
	t_room *head;
	char *line;
	int ret;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		return (0);
	head = room;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		//ft_printf("%p::%s\n", map,  line);
		if(!(ret = tarf_lawal(&map, l, &room, line)))
			return (ft_free_data(head, line));
		else if(ret == -1)
			room = tarf_lakhar(map, l, (t_room *[]){head, room}, line);
		if (!room || !(map->next = (t_map *)ft_memalloc(sizeof(t_map))))
			return (ft_free_data(head, line));
		map = map->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_free_room(&head);
	return (l->adlist != 0);
}

int get_links(t_lem_in **l, char *line)
{
	char **split;
	int room1;
	int room2;
	int i;

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

int get_nbants(t_lem_in *l, char *line)
{
	int len;
	int i;

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

static int is_cord(char *nbr)
{
	int i;

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

int check_room(t_room **r, char *line)
{
	char **split;
	int ret;
	int i;

	i = -1;
	ret = 1;
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	if (!(split = ft_split_format(line, ' ')))
		return (0);
	while (split[++i] != NULL)
		if (i == 0)
			(*r)->name = ft_strdup(split[i]);
		else if (i == 1)
			(*r)->cords.x = ft_atoi(split[i]);
		else if (i == 2)
			(*r)->cords.y = ft_atoi(split[i]);
	if (i != 3)
		return (ft_free_split(split, 0));
	if (!is_cord(split[1]) || !is_cord(split[2]))
		return (ft_free_split(split, 0));
	if (!((*r)->next = (t_room *)ft_memalloc(sizeof(t_room))))
		return (0);
	(*r) = (*r)->next;
	return (ft_free_split(split, 1));
}

int get_rooms(t_lem_in *l, t_room **a, t_map **map, char *line)
{
	if (!ft_strcmp((*map)->data, "##start"))
	{
		if (!check_room(a, line))
			return (0);
		if (!((*map)->next = (t_map *)malloc(sizeof(t_map))))
			return (0);
		ft_memset((void *)(*map)->next, 0, sizeof(t_map));
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
		ft_memset((void *)(*map)->next, 0, sizeof(t_map));
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		l->end = l->nbrooms;
		l->nbrooms += 1;
	}
	return (1);
}
