/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:20:51 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/09 04:59:18 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#define ANTS 01
#define START_ROOMS 2
#define START_LINKS 4
#define START_TOKEN 8
#define END_TOKEN 16

int check_cmd(char *line,t_map **tmp,int *flag)
{
	int start;
	char *line2;

	if((start = ft_strequ(line,"##start")) || ft_strequ(line,"##end"))
	{
		if(*flag & (start ? START_TOKEN : END_TOKEN))
			return(0);
		if (get_next_line(0, &line2) == 1)
		{
			if(!check_room(line2) || !(*tmp)->next = (t_map *)ft_memalloc(sizeof(t_map)))// gad check room lah yhafdek
			{
				free(line2);
				return(0);
			}
			(*tmp)->data = ft_strdup(line);
			(*tmp)->type = 4;
			(*tmp)->next->data = line2; 
			(*tmp)->next->type = start ? 6 : 7;
			*flag |= start ? START_TOKEN : END_TOKEN;
		}
	}
	return(4)
}

int get_line_type(char *line,t_map **tmp,int *flag)
{
	int i;

	i = 0;
	if (line[0] == '#' && line[1] != '#')
		return (5);
	if (!(*flag & ANTS))
	{
		if (!ft_is_numbre(line))
			return(0);
		*flag |= ANTS;
		return (1);
	}
	if (ft_strnequ(line, "##", 2))
		return(check_cmd(line, tmp, flag));
	else if(!(*flag & START_LINKS))
	{
		if(check_room(line))
			return(2);
	}
	*flag |= START_LINKS;
	while ((line = ft_strchr(line, '-')) && line++)
		i++;
	return((i == 1) * 3);
}

t_map *stok_map()
{
	t_map *head;
	t_map **tmp;
	char *line;
	int flag;

	line = NULL;
	head = NULL;
	flag = 0;
	tmp  = &head;
	while (get_next_line(0, &line) == 1)
	{
		*tmp = (t_map *)ft_memalloc(sizeof(t_map));
		if (!*tmp || !BETWEEN(((*tmp)->type = get_line_type(line, tmp, &flag)), 1, 7))
		{
			ft_free_map(head);
			return (NULL);
		}
		if (!(*tmp)->data)
			(*tmp)->data = ft_strdup(line);
		tmp = &(*tmp)->next;
		ft_strdel(&line);
	}
	return(head);
}