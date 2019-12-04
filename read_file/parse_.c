/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/12/04 19:36:18 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_adj(t_lem_in *adj)
{
	t_queue	*queue;
	t_queue	**lst;
	int		i;

	i = -1;
	queue = NULL;
	lst = adj->adlist;
	while (++i < adj->nbrooms)
	{
		queue = lst[i];
		ft_printf("index -> %d = ", i);
		while (queue != NULL)
		{
			ft_printf("%d -> ", queue->node);
			queue = queue->next;
		}
		ft_putchar('\n');
	}
}

int		is_valid(char *line, char del)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != del)
		i += 1;
	if (line[i] != del || line[0] == 'L' || line[0] == '#')
		return (0);
	return (1);
}

int		read_data(t_map *map, t_lem_in *l)
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
			if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			{
				ft_strdel(&line);
				get_next_line(0, &line);
				if (is_valid(line, ' ') && (l->start == -1 || l->end == -1))
				{
					if (!get_rooms(l, &room, &map, line))
					{
						ft_strdel(&line);
						exit(0);
					}
					ft_strdel(&line);
				}
			}
		}
		else if (is_valid(line, ' ') && check_room(&room, line))
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
		else if (is_valid(line, '-'))
		{
			if (i == 1 && (i = 2))
			{
				creat_rooms_array(l, head);
				ft_creat_adj(&l, l->nbrooms);
			}
			get_links(&l, line);
			map->data = ft_strdup(line);
			map->type = LINK;
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
	///ft_print_adj(l);
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

int		check_room(t_room **r, char *line)
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
	if (i != 3 || (ft_strcmp(ft_itoa((*r)->cords.x), split[1])
	|| ft_strcmp(ft_itoa((*r)->cords.y), split[2])))
	{
		ft_putendl("Room not valid !!");
		exit(0);
	}
	(*r) = (*r)->next;
	return (1);
}

int		get_rooms(t_lem_in *l, t_room **a, t_map **map, char *line)
{
	if (!ft_strcmp((*map)->data, "##start"))
	{
		check_room(a, line);
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
		check_room(a, line);
		if (!((*map)->next = (t_map *)malloc(sizeof(t_map))))
			return (0);
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		(*map)->type = END;
		l->end = l->nbrooms;
		l->nbrooms += 1;
	}
	return (1);
}

// int		main(void)
// {
// 	t_lem_in	l;
// 	t_map		*map;
// 	t_map		*head;

// 	map = (t_map *)malloc(sizeof(t_map));
// 	ft_memset(map, 0, sizeof(t_map));
// 	head = map;
// 	read_data(map, &l);
// 	while (head->next != NULL)
// 	{
// 		ft_printf("{data : %s} => {type : %d} {nbroom : %d}\n", head->data, head->type, l.nbrooms);
// 		head = head->next;
// 	}
// 	return (0);
// }
