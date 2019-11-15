/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/16 00:15:45 by mobouzar         ###   ########.fr       */
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
		}
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

int		get_rooms(t_lem_in *l)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "##start"))
		{
			
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
	while (head->next != NULL)
	{
		ft_putendl(head->data);
		head = head->next;
	}
	return (0);
}
