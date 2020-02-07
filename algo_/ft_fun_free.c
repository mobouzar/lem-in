/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:58 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/07 12:35:57 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			ft_free_tab(char ***tab)
{
	int			i;
	char		**str;

	i = 0;
	if (!(*tab))
		return ;
	str = *tab;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_memdel((void **)tab);
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

	if ((*init))
	{
		p = getset(0);
		i = 0;
		while ((*init)[i] && i < j)
		{
			ft_free_init_(&(*init)[i]);
			i++;
		}
		ft_memdel((void **)init);
	}
}

void			ft_free_queue__(t_queue **lst)
{
	if ((*lst) && (*lst)->next)
		ft_free_queue__(&(*lst)->next);
	ft_memdel((void **)lst);
}

static void		ft_free_group(t_group **g)
{
	if ((*g) && (*g)->next)
		ft_free_group(&(*g)->next);
	ft_memdel((void **)&(*g)->grp);
	ft_memdel((void **)g);
}

void			ft_struct_lem_in(t_lem_in **l)
{
	int			i;

	i = -1;
	while ((*l)->adlist && ++i < (*l)->nbrooms)
		ft_free_queue__(&(*l)->adlist[i]);
	if ((*l)->adlist)
		ft_memdel((void **)&(*l)->adlist);
	if ((*l)->g[0])
		ft_free_group(&(*l)->g[0]);
	if ((*l)->g)
		ft_memdel((void **)&(*l)->g);
	//ft_free_tab(&(*l)->rooms);
	ft_memdel((void **)&(*l));
}
