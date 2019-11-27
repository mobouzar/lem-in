#include "lem_in.h"


static void		ft_push_queue(t_queue **lst, int node)
{
	//ft_printf("\nnode = %d\n", node);
	if (!(*lst))
	{
		if (!((*lst)= (t_queue *)malloc(sizeof(t_queue))))
			return ;
		(*lst)->node = node;
		(*lst)->flow = 0;
		(*lst)->next = NULL;
	}
	else
	{
		if (!((*lst)->next = (t_queue *)malloc(sizeof(t_queue))))
			return ;
		(*lst)->next->node = node;
		(*lst)->next->flow = 0;
		(*lst) = (*lst)->next;
	}
}


static t_queue			*ft_front_queue(t_queue **q)
{
	t_queue *tmp;

	tmp = NULL;
	tmp = *q;
	if ((*q)->next)
		(*q) = (*q)->next;
	else
		(*q) = NULL;
	return (tmp);
}

static	void _init(t_bfs **bfs, int nbroom , int strat)
{
	t_bfs *lst;

	lst = (*bfs);
	if (!((*bfs) = (t_bfs *)malloc(sizeof(t_bfs))))
			return ;
	ft_memset((*bfs), '\0', sizeof(t_bfs));
	if (!((*bfs)->vist = (int *)malloc(sizeof(int) * (nbroom))))
		return ;
	ft_memset((*bfs)->vist, -1, sizeof(int) * (nbroom));
	ft_push_queue(&(*bfs)->last, strat);
	(*bfs)->vist[0] = 0;
	(*bfs)->q = (*bfs)->last;
}

void		ft_free_queue(t_queue **lst)
{
	t_queue	*tmp;

	if ((*lst))
	{
		while ((*lst))
		{
			tmp = (*lst);
			(*lst) = (*lst)->next;
			ft_memdel((void	**)&tmp);
		}
	}
}


void	ft_index_path(t_adjs *lst,  int end_room, int strat)
{
	int i;
	t_queue *q;

	i = 0;
	q = lst->adjs[strat];
//	ft_printf("%d		%d\n", end_room, strat);
	while (q)
	{
		if (q->node == end_room)
		{
			q->flow = 2;
		}
		q = q->next;
	}
}



int		*_bfs(t_lem_in *lem, t_adjs *adj)
{
	t_bfs *lst;
	t_queue *tmp;
	t_queue *queue;
	
	_init(&lst, 13, 0);//lem->nbrooms
	while (lst->q)
	{
		tmp = ft_front_queue(&lst->q);
		queue = adj->adjs[tmp->node];
		while (queue)
		{ 
			if (queue->node == 13)
			{
				lst->vist[queue->node] = tmp->node;
				//ft_free_queue(&lst->q);
				return (lst->vist);
			}
			if (lst->vist[queue->node] == -1 && queue->flow == 0)
			{
				lst->vist[queue->node] = tmp->node;
				ft_push_queue(&lst->last, queue->node);	
				if (!(lst->q))
					lst->q = lst->last;
			}
			queue = queue->next;
		}
		ft_memdel((void **)&tmp);
	}
	return (0);
}
