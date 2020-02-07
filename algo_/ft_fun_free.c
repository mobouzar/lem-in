/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:58 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/07 10:29:00 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			ft_free_tab(char ***tab)
{
	int			i;
	char		**str;

	i = 0;
	str = *tab;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}

static void		ft_free_init_(t_print **init)
{
	if ((*init) && (*init)->next)
		ft_free_init_(&(*init)->next);
	ft_strdel(&(*init)->name);
	ft_memdel((void **)init);
}

void			ft_free_init(t_print ***init, int j)
{
	t_lem_in	*p;
	int			i;

	p = getset(0);
	i = 0;
	while ((*init)[i] && i < j)
	{
		ft_free_init_(&(*init)[i]);
		i++;
	}
	ft_memdel((void **)init);
}

void			ft_free_queue__(t_queue **lst)
{
	if ((*lst) && (*lst)->next)
		ft_free_queue__(&(*lst)->next);
	ft_memdel((void **)lst);
}
