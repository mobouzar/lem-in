/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_adjs_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:52:32 by yelazrak          #+#    #+#             */
/*   Updated: 2019/11/27 22:06:45 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_creat_adjs(t_adjs **lst,int nbroom)
{
	t_adjs *tmp;

	if (!(tmp = (t_adjs *)malloc(sizeof(t_adjs))))
		return ;
	ft_memset((void *)tmp, '\0',sizeof(t_adjs));	
	tmp->nbroom = nbroom;
	if (!(tmp->adjs = (t_queue **)malloc(sizeof(t_queue *) * (nbroom))))
		return ;
	ft_memset((void *)tmp->adjs, '\0', sizeof(t_queue *) * (nbroom));	
	*lst = tmp;
}

void	ft_add_node(t_adjs **list_adj, int nbr_1, int nbr_2)
{
	t_queue *tmp_1;
	t_queue *tmp_2;
	t_queue **lst;
	t_adjs *adj;

	adj = *list_adj;
	lst = adj->adjs;
	if (!(tmp_1 = (t_queue *)malloc(sizeof(t_queue))))
		return ;
	if (!(tmp_2 = (t_queue *)malloc(sizeof(t_queue))))
		return ;
	tmp_1->node = nbr_1;
	tmp_1->next = NULL;
	tmp_2->node = nbr_2;
	tmp_2->next = NULL;
	if (lst[nbr_1])
		tmp_2->next = lst[nbr_1];
	lst[nbr_1] = tmp_2;
	if (lst[nbr_2])
		tmp_1->next  = lst[nbr_2];
   	lst[nbr_2] = tmp_1;
}

void		ft_print_adj(t_adjs *adj)
{
	int i;
	t_queue *q;
	t_queue **lst;

	i = -1;
	lst = adj->adjs;
	q = NULL;
	while (++i < adj->nbroom)
	{
		q = lst[i];
		ft_printf("%d ==> ", i);
		while (q)
		{
			if (q->next)
			{
				ft_putnbr_fd(q->node, 1);
				ft_putstr_fd("==>", 1);
			}
			else
				ft_printf("%d ;\n",q->node);
			q = q->next;
		}
	}
}

void		ft_fill_(t_adjs **lst)
{
	ft_creat_adjs(lst, 14);
	// ft_add_node(lst, 0, 1);
	// ft_add_node(lst, 0, 3);
	// ft_add_node(lst, 3, 4);
	// ft_add_node(lst, 1, 5);
	// ft_add_node(lst, 1, 2);
	// ft_add_node(lst, 4, 2);
	// ft_add_node(lst, 2, 7);
	// ft_add_node(lst, 6, 7);
	// ft_add_node(lst, 5, 6);
	ft_add_node(lst, 0, 1);
	ft_add_node(lst, 0 , 2 );
	ft_add_node(lst, 0 , 3 );
	ft_add_node(lst, 1 , 4 );
	ft_add_node(lst, 2 , 5 );
	ft_add_node(lst, 3 , 8 );
	ft_add_node(lst,  3,6  );
	ft_add_node(lst,  4, 7 );
	ft_add_node(lst, 5 , 8 );
	ft_add_node(lst, 6 , 9 );
	ft_add_node(lst, 7 , 10 );
	ft_add_node(lst, 8 , 10 );
	ft_add_node(lst, 8 , 11 );
	ft_add_node(lst,  9, 12 );
	ft_add_node(lst,  10, 13 );
	ft_add_node(lst, 11 , 13 );
	ft_add_node(lst,  12, 13  );
	

	
}
static void		ft_get_path_(t_adjs *lst, int *path, int i)
{

	if (i == 0 || path == NULL)
		return ;

	ft_get_path_(lst, path, path[i]);//
	ft_printf("%d ==> ",path[i]);
	 ft_index_path(lst, i, path[i]);
	 ft_index_path(lst,  path[i], i);
	
}
int main()
{
	t_adjs *lst;
	t_lem_in *lem;
	int		*path;

	if (!(lem = (t_lem_in *)malloc(sizeof(t_lem_in))))
		return 0;
	ft_memset((void *)lem, '\0', sizeof(t_lem_in));
	lem->start = 0;
	lem->end = 13;
	path = NULL;
	ft_fill_(&lst);
	path = _bfs(lem, lst);
	ft_get_path_(lst, path,  13);
		if (path)
			ft_printf("13\n");
	path = NULL;

	path = _bfs(lem, lst);
	ft_get_path_(lst, path,  13);

	if (path)
		ft_printf("13\n");
	path = NULL;
	path = _bfs(lem, lst);
	ft_get_path_(lst, path,  13);
	if (path)
		ft_printf("13\n");
	//ft_print_adj(lst);
}































