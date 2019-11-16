/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/16 00:40:53 by mydevice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_map(t_map *map)
{
	t_map		*m;
	char		*line;
	int			i;
	
	i = 0;
	while (get_next_line(0, &line))
	{
		m = (t_map *)malloc(sizeof(t_map));
		m->next = NULL;
		m->map = ft_strdup(line);
		m = m->next;
	}
	m->next = NULL;
	return (1);
}

int		get_nbrofants(t_lem_in *l, char *line)
{
	// char	*line;
	int		len;
	int		i;

	i = 0;
	l->nbants = -1;
	// get_next_line(0, &line);
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

int	main(int ac, char **av)
{
	t_map		*m;

	m = (t_map *)malloc(sizeof(t_map));
	read_map(m);
	while (m->next != NULL)
	{
		ft_printf("%s\n", m->map);
		m = m->next;
	}
	return (0);
}
