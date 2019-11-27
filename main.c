/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/27 23:52:51 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_valid(char *line, char del)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != del)
		i += 1;
	if (line[i] != del && (line[0] == 'L' || line[0] == '#'))
		return (0);
	return (1);
}

int		read_data(t_map *map, t_lem_in *l, t_adlist **adlist)
{
	t_room		*room;
	t_room		*head;
	char		*line;
	int			i;

	i = 0;
	l->nbrooms = 0;
	l->start = -1;
	l->end = -1;
	room = (t_room *)malloc(sizeof(t_room));
	ft_memset(room, 0, sizeof(t_room));
	head = room;
	while (get_next_line(0, &line))
	{
		if (i == 0 && get_nbants(l, line) && (i = 1))
		{
			map->data = ft_strdup(line);
			map->type = NBANTS;
		}
		else if (line[0] == '#' && line[1] == '#')
		{
			map->data = ft_strdup(line);
			map->type = COMMAND;
			ft_strdel(&line);
			get_next_line(0, &line);
			if ((l->start == -1 || l->end == -1) && (line[0] != '#' || line[0] != 'L'))
			{
				if (!get_rooms(l, &room, &map, line))
				{
					ft_strdel(&line);
					exit(0);
				}
				ft_strdel(&line);
			}
		}
		else if (is_valid(line, ' ') && check_room(l, &room, map, line))
		{
			map->data = ft_strdup(line);
			map->type = ROOM;
			l->nbrooms += 1;
		}
		else if (line[0] == '#' && line[1] != '#')
		{
			map->data = ft_strdup(line);
			map->type = COMMENT;
		}
		else
			break ;
		map->next = (t_map *)malloc(sizeof(t_map));
		map = map->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	map->next = NULL;
	room->next = NULL;
	// ft_printf("%s\n", room->name);
	// while (head->next)
	// {
	// 	ft_printf("name => |%s|, x => |%d|, y => |%d| , index => %d\n", head->name, head->cords.x, head->cords.y, head->index);
	// 	head = head->next;
	// }
		
	return (1);
}

int		get_nbants(t_lem_in *l, char *line)
{
	int		len;
	int		i;

	i = 0;
	l->nbants = -1;
	len = ft_strlen(line);
	while (len <= 10 && line[i])
		if (ft_isdigit(line[i]))
			i++;
		else
		{
			ft_putendl("Number ants not valid!");
			exit(0);
		}
	if (len <= 10)
		l->nbants = ft_atoi(line);
	if (l->nbants == 0 || len > 10)
	{
		ft_putendl("Number ants not valid!");
		exit(0);
	}
	return (1);
}

int		check_room(t_lem_in *l, t_room **r, t_map *m, char *line)
{
	char	**split;
	int		i;

	(*r)->next = (t_room *)malloc(sizeof(t_room));
	if (line[0] == 'L' || line[0] == '#')
	{
		ft_putendl("Room not valid !!");
		exit(0);
	}
	split = ft_split_format(line, ' ');
	i = -1;
	while (split[++i] != NULL)
		if (i == 0)
			(*r)->name = ft_strdup(split[i]);
		else if (i == 1)
			(*r)->cords.x = ft_atoi(split[i]);
		else if (i == 2)
			(*r)->cords.y = ft_atoi(split[i]);
	(*r)->index = l->nbrooms;
	if (i != 3 || (ft_strcmp(ft_itoa((*r)->cords.x), split[1])
	|| ft_strcmp(ft_itoa((*r)->cords.y), split[2])))
	{
		ft_putendl("Room not valid !!");
		exit(0);
	}
	// ft_printf("name => |%s|, x => |%d|, y => |%d| , index => %d\n", (*r)->name, r->cords.x, r->cords.y, r->index);
	(*r) = (*r)->next;
	return (1);
}

int		get_rooms(t_lem_in *l, t_room **a, t_map **map, char *line)
{
	if (!ft_strcmp((*map)->data, "##start"))
	{
		check_room(l, a, (*map), line);
		if (!((*map)->next = (t_map *)malloc(sizeof(t_map))))
			return (0);
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		(*map)->type = START;
		l->start = l->nbrooms;
		l->nbrooms += 1;
	}
	else if (!ft_strcmp((*map)->data, "##end"))
	{
		check_room(l, a, (*map), line);
		if (!((*map)->next = (t_map *)malloc(sizeof(t_map))))
			return (0);
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		(*map)->type = END;
		l->end = l->nbrooms;
		l->nbrooms += 1;
	}
	else
	{
		ft_putendl("START or END not found !!");
		return (0);
	}
	// ft_printf("start => %d end => %d\n", l->start, l->end);
	return (1);
}

int		contains(char *room)
{
	return 0;
}

int		get_links(t_lem_in *l, t_map **map, t_adlist **adlst, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split_format(line, '-');
	while (split[i])
		i += 1;
	if (i != 2)
	{
		ft_putendl("Error");
		exit(0);
	}
	
	return (1);
}

int		main(void)
{
	t_lem_in	l;
	t_adlist	*adlist;
	t_map		*map;
	t_map		*head;
	

	map = (t_map *)malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	adlist = (t_adlist *)malloc(sizeof(adlist));
	head = map;
	read_data(map, &l, &adlist);
	ft_printf("%d %d\n", l.start, l.end);
	while (head->next != NULL)
	{
		ft_printf("{data : %s} => {type : %d} {nbroom : %d}\n", head->data, head->type, l.nbrooms);
		head = head->next;
	}
	int i = 0;
	// while (i < l.nbrooms)
	// {
	// 	// ft_putendl(l.rooms->room);
	// 	ft_printf("room => %s x => %d y => %d\n", l.rooms->room, l.rooms->cords.x, l.rooms->cords.y);
	// 	i++;
	// }
	return (0);
}
