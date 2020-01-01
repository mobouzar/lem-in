#include "../include/lem_in.h"


static void		ft_push_queue(t_queue **lst, int node)
{
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
		(*lst)->next->next = NULL;
		(*lst) = (*lst)->next;
	}
}

int ft_index_path_cap(t_lem_in *lst,  int end_room, int strat, int index)
{
	t_queue *q;

	q = lst->adlist[strat];
	while (q)
	{
		if (q->node == end_room)
		{
			if (q->flow == index) //1)
			{
				q->flow = -2;
				return (1);
			}
		}
		q = q->next;
	}
	return (0);
}

static t_queue			*ft_front_queue(t_queue **q)
{
	t_queue *tmp;

	tmp = NULL;
	tmp = *q;
	tmp = *q;
	if ((*q)->next)
		(*q) = (*q)->next;
	else
		(*q) = NULL;
	return (tmp);
}

static	void _init(t_bfs **bfs,int **vist, int nbroom , int strat)
{
	if (!((*bfs) = (t_bfs *)malloc(sizeof(t_bfs))))
		return ;
	ft_memset((*bfs), '\0', sizeof(t_bfs));
	if (!((*vist) = (int *)malloc(sizeof(int) * (nbroom))))
		return ;
	ft_memset((*vist), -1, sizeof(int) * (nbroom));
	ft_push_queue(&(*bfs)->last, strat);
	(*vist)[strat] = 0;
	(*bfs)->q = (*bfs)->last;
}




void	ft_index_path(t_lem_in *lem, int end_room, int strat, int index)
{
	t_queue *q;

	q = lem->adlist[strat];
	while (q)
	{
		if (q->node == end_room)
		{
			if (ft_index_path_cap(lem, strat,   end_room, index))
			{
					q->flow = -2;
			}
			else
			{
				q->flow++;
			}	
		}
		q = q->next;
	}
}

int		*_bfs(t_lem_in *lem, int c)
{
	t_bfs *lst;
	t_queue *tmp;
	t_queue *queue;
	int 	*vist;
	
	(void)lem;
	_init(&lst, &vist,lem->nbrooms, lem->start);
	while (lst->q)
	{
		tmp = ft_front_queue(&lst->q);
		queue = lem->adlist[tmp->node];
		while (queue)
		{
			if (queue->node == lem->end && queue->flow == c)
			{
				vist[queue->node] = tmp->node;
				ft_free_queue(&lst->q);
				ft_memdel((void **)&lst);
				return (vist);
			}
			if (vist[queue->node] == -1 && queue->flow == c)
			{
				vist[queue->node] = tmp->node;
				ft_push_queue(&lst->last, queue->node);	
				if (!(lst->q))
				lst->q = lst->last;
			}
			queue = queue->next;
		}
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&lst);
	return (0);
}
