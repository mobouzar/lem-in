/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:15:11 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/09 06:13:38 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lem_in.h"

// static void				print_data1(t_map *data)
// {
// 	// int i = 0;
// 	while (data && data->next)
// 	{
// 		// ft_printf("%d\n", i++);
// 		ft_printf("%s\n", data->data);
// 		data = data->next;
// 	}
// 	ft_printf("\n");
// }

int					main(void)
{
	t_lem_in		*l;
	t_map			*map;
	t_map			*head;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (1);
	if (!(l = (t_lem_in *)malloc(sizeof(t_lem_in))))
		return (1);
	head = map;
	ft_memset((void *)l, '\0', sizeof(t_lem_in));
	ft_memset((void *)map, '\0', sizeof(t_map));
	l->start = -1;
	l->end = -1;
	if (!read_data(map, l))
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
