/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/16 23:56:09 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_data(t_map *map, t_lem_in *l)
{
	char		*line;
	char		*cmd;
	int			i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (get_nbants(l, line))
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
			if (line[0] != '#' && line[0] != 'L')
			{
				if (!get_rooms(l, &map, line, cmd))
				{
					ft_strdel(&cmd);
					ft_strdel(&line);
					exit(1);
				}
				ft_strdel(&cmd);
				ft_strdel(&line);
			}
		}
		else if (line[0] != '#' && line[0] != 'L' && line[1] == ' ')
		{
			if (check_room(l, map, line))
			{
				map->data = ft_strdup(line);
				map->type = ROOM;
			}
		}
		else
			map->data = ft_strdup(line);
		map->next = (t_map *)malloc(sizeof(t_map));
		map = map->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	map->next = NULL;
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
			return (0);
	if (len <= 10)
		l->nbants = ft_atoi(line);
	if (l->nbants == 0 && len > 10)
		return (0);
	return (1);
}

int		check_room(t_lem_in *l, t_map *m, char *line)
{
	char	**split;
	int		i;
	if (line[0] == 'L' && line[0] == '#')
		return (0);
	split = ft_strsplit(line, ' ');
	i = 0;
	while (split[i] != NULL)
		i++;
	l->rooms->room = ft_strdup(split[0]);
	l->rooms->cords.x = ft_atoi(split[1]);
	l->rooms->cords.y = ft_atoi(split[2]);
	if (ft_strcmp(ft_itoa(l->rooms->cords.x), split[1])
	|| ft_strcmp(ft_itoa(l->rooms->cords.y), split[2]) || i != 3)
		return (0);
	return (1);
}

int		get_rooms(t_lem_in *l, t_map **map, char *line, char *cmd)
{
	l->rooms = (t_room *)malloc(sizeof(t_room));
	if (!ft_strcmp(cmd, "##start"))
	{
		if (!check_room(l, (*map), line))
			return (0);
		(*map)->next = (t_map *)malloc(sizeof(t_map));
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		(*map)->type = START;
	}
	else if (!ft_strcmp(cmd, "##end"))
	{
		if (!check_room(l, (*map), line))
			return (0);
		(*map)->next = (t_map *)malloc(sizeof(t_map));
		(*map) = (*map)->next;
		(*map)->data = ft_strdup(line);
		(*map)->type = END;
	}
	else
		return (0);
	return (1);
}

int		main(void)
{
	t_lem_in	l;
	t_map		*map;
	t_map		*head;
	
	map = (t_map *)malloc(sizeof(t_map));
	head = map;
	read_data(map, &l);
	while (head->next != NULL)
	{
		ft_printf("%s => %d\n", head->data, head->type);
		head = head->next;
	}
	return (0);
}
