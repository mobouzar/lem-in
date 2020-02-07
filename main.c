/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:15:11 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/07 12:34:23 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lem_in.h"

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
	read_data(map, l);
	getset(l);
	ft_mangement_instructoin(l, head);
	ft_struct_lem_in(&l);
	return (0);
}
