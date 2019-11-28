/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/22 23:59:13 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_data(t_map *map, t_lem_in *l)
{
	char		*line;
	char		*cmd;
	int			i;

	i = 0;
	l->nbrooms = 0;
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
			cmd = ft_strdup(line);
			ft_strdel(&line);
			get_next_line(0, &line);
			if (line[0] != '#' || line[0] != 'L')
			{
				if (!get_rooms(l, &map, line, cmd))
				{
					ft_strdel(&cmd);
					ft_strdel(&line);
					exit(0);
				}
				ft_strdel(&cmd);
				ft_strdel(&line);
			}
		}
		else if (line[1] == ' ' && check_room(l, map, line))
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
	// l->rooms = NULL;
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

int		check_room(t_lem_in *l, t_map *m, char *line)
{
	char	**split;
	int		i;

	l->rooms = (t_room *)malloc(sizeof(t_room));
	if (line[0] == 'L' || line[0] == '#')
	{
		ft_putendl("Room not valid !!");
		exit(0);
	}
	split = ft_strsplit(line, ' ');
	i = -1;
	while (split[++i] != NULL)
		if (i == 0)
			l->rooms->room = ft_strdup(split[i]);
		else if (i == 1)
			l->rooms->cords.x = ft_atoi(split[i]);
		else if (i == 2)
			l->rooms->cords.y = ft_atoi(split[i]);
	if (i != 3 || (ft_strcmp(ft_itoa(l->rooms->cords.x), split[1])
	|| ft_strcmp(ft_itoa(l->rooms->cords.y), split[2])))
	{
		ft_putendl("Room not valid !!");
		exit(0);
	}
	return (1);
}

int		get_rooms(t_lem_in *l, t_map **map, char *line, char *cmd)
{
	if (!ft_strcmp(cmd, "##start"))
	{
		check_room(l, (*map), line);
		(*map)->next = (t_map *)malloc(sizeof(t_map));
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		(*map)->type = START;
		l->nbrooms += 1;
	}
	else if (!ft_strcmp(cmd, "##end"))
	{
		check_room(l, (*map), line);
		(*map)->next = (t_map *)malloc(sizeof(t_map));
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		(*map)->type = END;
		l->nbrooms += 1;
	}
	else
	{
		ft_putendl("START or END not found !!");
		return (0);
	}
	return (1);
}
#include <stdio.h>
int		main(void)
{
	t_lem_in	l;
	t_map		*map;
	t_map		*head;
	
	map = (t_map *)malloc(sizeof(t_map));
	head = map;
	read_data(map, &l);
	// while (head->next != NULL)
	// {
	// 	ft_printf("{data : %s} => {type : %d} {nbroom : %d}\n", head->data, head->type, l.nbrooms);
	// 	head = head->next;
	// }
	int i = 0;
	while (i < l.nbrooms)
	{
		// ft_putendl(l.rooms->room);
		printf("room => %s x => %d y => %d\n", l.rooms->room, l.rooms->cords.x, l.rooms->cords.y);
		i++;
	}
	
	return (0);
}
