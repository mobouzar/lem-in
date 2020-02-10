/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:15:11 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/10 15:28:33 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lem_in.h"

int					main(void)
{
	t_lem_in		*l;
	t_map			*map;
	t_map			*head;

	if (!(l = (t_lem_in *)ft_memalloc(sizeof(t_lem_in))))
		return (1);
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (1);
	head = map;
	l->start = -1;
	l->end = -1;
	if (!read_data(&l, (t_map *[]){head, map}) || !l->adlist)
	{
		ft_memdel((void*)&l);
		ft_free_map(&head);
		ft_putendl("Error");
		return (1);
	}
	getset(l);
	ft_mangement_instructoin(l, head);
	ft_struct_lem_in(&l, &head);
	return (0);
}
