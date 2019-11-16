/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/16 02:52:01 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_data(t_map *map, t_lem_in *l)
{
	char		*line;
	int			i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (get_nbants(l, line))
		{
			map->type = NBANTS;
			map->data = ft_strdup(line);
		}
		else if (line[0] == '#' && line[1] == '#')
		{
			map->type = COMMAND;
			map->data = ft_strdup(line);
		}
		else
			map->data = ft_strdup(line);
		map->next = (t_map *)malloc(sizeof(t_map));
		map = map->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	map->next = NULL;
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

int		get_rooms(t_lem_in *l, char *line)
{
	char	**split;
	int		i;

	if (!ft_strcmp(line, "##start"))
	{
		ft_strdel(&line);
		get_next_line(0, line);
		if (line[0] != 'L' && line[0] != '#')
		{
			split = ft_strsplit(line, ' ');
			i = 0;
			while (split[i] != NULL)
				i++;
			l->room->room = ft_strdup(split[0]);
			l->room->cords.x = ft_atoi(split[1]);
			l->room->cords.y = ft_atoi(split[2]);
			if (ft_strcmp(l->room->cords.x, split[1]) || ft_strcmp(l->room->cords.y, split[2]) || i != 3)
				return (0);
		}
	}
	return (1);
}

int	main(void)
{
	t_lem_in	l;
	t_map		*map;
	t_map		*head;
	
	map = (t_map *)malloc(sizeof(t_map));
	head = map;
	read_data(map, &l);
	ft_printf("%d\n", head->type);
	while (head->next != NULL)
	{
		ft_putendl(head->data);
		head = head->next;
	}
	return (0);
}
