/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:58 by yelazrak          #+#    #+#             */
/*   Updated: 2019/12/24 22:27:48 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		ft_free_tab(char ***tab)
{
	int		i;
	char	**str;

	i = 0;
	str = *tab;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}

void		ft_free_queue(t_queue **lst)
{
	t_queue *tmp;

	if ((*lst))
	{
		while ((*lst))
		{
			tmp = (*lst);
			(*lst) = (*lst)->next;
			ft_memdel((void **)&tmp);
		}
	}
}
