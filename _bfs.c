#include "lem_in.h"


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
	t_bfs *lst;

	lst = (*bfs);
	if (!((*bfs) = (t_bfs *)malloc(sizeof(t_bfs))))
			return ;
	ft_memset((*bfs), '\0', sizeof(t_bfs));
	if (!((*vist) = (int *)malloc(sizeof(int) * (nbroom))))
		return ;
	ft_memset((*vist), -1, sizeof(int) * (nbroom));
	ft_push_queue(&(*bfs)->last, strat);
	(*vist)[0] = 0;
	(*bfs)->q = (*bfs)->last;
}




void	ft_index_path(t_adjs *lst,  int end_room, int strat)
{
	int i;
	t_queue *q;

	i = 0;
	q = lst->adjs[strat];
//	ft_printf("%d		%d\n", strat , end_room);
	while (q)
	{
		//ft_printf("strat = %d	node =%d		flow = %d\n",strat, q->node , q->flow );
		if (q->node == end_room)
		{
			if (ft_index_path_cap(lst, strat,   end_room))
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



int		*_bfs(t_lem_in *lem, t_adjs *adj, int c)
{
	t_bfs *lst;
	t_queue *tmp;
	t_queue *queue;
	int 	*vist;
	
	(void)lem;
	_init(&lst, &vist,8, 0);//lem->nbrooms
	while (lst->q)
	{
		tmp = ft_front_queue(&lst->q);
		queue = adj->adjs[tmp->node];
		while (queue)
		{
			if (queue->node == 7 && queue->flow == c)
			{
				//printf("p = %d			f = %d\n",tmp->node,queue->node);
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
