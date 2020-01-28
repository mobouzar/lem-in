#include "../include/lem_in.h"



// int h = 0;
			// dprintf((h = open("/dev/ttys003", O_RDWR)), "tmp=%d		queue=%d  	nnnoodd = %d	 visit_tmp=%s =>%s		int=%d			node[] = %d\n",
			// 		ft_index_node(lem, tmp->node, queue->node, c, node), ft_index_node(lem, vist[tmp->node], tmp->node, c, node), ft_node(lem,tmp->node,vist[tmp->node], c, node),lem->rooms[tmp->node], lem->rooms[queue->node], c, node[tmp->node]);
			// close(h);
			/*******************/

			// if (vist[queue->node] == -1 && queue->flow == c &&
			// ((node[tmp->node] == 0 || (node[tmp->node] == 1 &&
			// ((ft_index_node(lem, tmp->node, queue->node, c, node) == 0) &&  node[queue->node] == 1 &&
			// ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1))) ||
			// (node[tmp->node] == 1  &&  ft_index_node(lem, tmp->node, queue->node, c, node) == 0 &&
			// ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0 && ft_node(lem,tmp->node,vist[tmp->node], c, node) == 1 ) ||
			// ((
			// (ft_index_node(lem, tmp->node, queue->node, c, node) == 1 &&
			// ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0))) ||
			// ((
			// (ft_index_node(lem, tmp->node, queue->node, c, node) == 0 && node[vist[tmp->node]] == 1 &&
			// ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))

			/***************************************************/
			// if (vist[queue->node] == -1 && queue->flow == c &&
			// 	(node[tmp->node] == 0 || ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 &&
			// 							ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ))||
			// 			   ( (ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0 ||
			// 				(ft_index_node(lem, tmp->node, queue->node, c, node) == 0))))
			// if (vist[queue->node] == -1 && queue->flow == c && y == 0 &&
			// 	(node[tmp->node] == 0 || (node[tmp->node] == 1 && ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 && node[vist[tmp->node]] == 0 && node[queue->node] == 1 &&
			// 														ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ||
			// 													   (node[vist[tmp->node]] == 1 && ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))

static void ft_push_queue(t_queue **lst, int node)
{
	if (!(*lst))
	{
		if (!((*lst) = (t_queue *)malloc(sizeof(t_queue))))
			return;
		(*lst)->node = node;
		(*lst)->flow = 0;
		(*lst)->next = NULL;
	}
	else
	{
		if (!((*lst)->next = (t_queue *)malloc(sizeof(t_queue))))
			return;
		(*lst)->next->node = node;
		(*lst)->next->flow = 0;
		(*lst)->next->next = NULL;
		(*lst) = (*lst)->next;
	}
}

int ft_index_path_cap(t_lem_in *lst, int end_room, int strat, int index)
{
	t_queue *q;
	int i;
	(void)index;

	i = (index == 0 ? 1 : 0);
	q = lst->adlist[strat];
	while (q)
	{
		if (q->node == end_room)
		{
			if (q->flow == i) //index) //1)
			{
				q->flow =  -2;//(i == 0 ? 1 : 0); //-2
				return (1);
			}
		}
		q = q->next;
	}
	return (0);
}
void ft_index_path(t_lem_in *lem, int end_room, int strat, int index)
{
	t_queue *q;

	q = lem->adlist[strat];
	while (q)
	{
		if (q->node == end_room)
		{
			if (ft_index_path_cap(lem, strat, end_room, index))
				q->flow = -2;//(index == 0 ? 1 : 0); //-2;
			else
				q->flow = (index == 0 ? 1 : 0);
		}
		q = q->next;
	}
}

static t_queue *ft_front_queue(t_queue **q)
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

static void _init(t_bfs **bfs, int **vist, int nbroom, int strat)
{
	(*bfs) = NULL;
	if (!((*bfs) = (t_bfs *)malloc(sizeof(t_bfs))))
		return;
	ft_memset((*bfs), '\0', sizeof(t_bfs));
	if (!((*vist) = (int *)malloc(sizeof(int) * (nbroom))))
		return;
	ft_memset((*vist), -1, sizeof(int) * (nbroom));
	ft_push_queue(&(*bfs)->last, strat);
	(*vist)[strat] = 0;
	(*bfs)->q = (*bfs)->last;
}


int ft_index_node(t_lem_in *lem, int end_room, int strat, int index, int *node)
{
	t_queue *q;
	int i;
	(void)index;
	(void)node;
	q = lem->adlist[strat];
	i = (index == 0 ? 1 : 0);
	while (q)
	{
		if (q->node == end_room)
		{
			if (q->flow == i /*&& node[end_room] == 1 && node[strat] == 1*/) //index + 1)
				return (0);
			else
				return (1);
		}
		q = q->next;
	}
	return (1);
}


// if (vist[queue->node] == -1 && queue->flow == c &&
// 			(node[tmp->node] == 0 || (node[tmp->node] == 1  && ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 && node[vist[tmp->node]] == 0 && node[queue->node] == 1  &&
// 			 ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ||
// 			( node[vist[tmp->node]] == 1 && ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))

// if (vist[queue->node] == -1 && queue->flow == c && y == 0 &&
// 			(node[tmp->node] == 0 || (node[tmp->node] == 1  && ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 && node[vist[tmp->node]] == 0 && node[queue->node] == 1  &&
// 			 ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ||
// 			( node[vist[tmp->node]] == 1 && ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))
int *_bfs(t_lem_in *lem, int c, int *node, int y, int count)
{
	t_bfs *lst;
	t_queue *tmp;
	t_queue *queue;
	int *vist;
	int t = 0;

	(void)lem;
	(void)node;
	(void)count;
	_init(&lst, &vist, lem->nbrooms, lem->start);
	while (lst->q)
	{
		tmp = ft_front_queue(&lst->q);
		queue = lem->adlist[tmp->node];
		t = 0;
		while (queue)
		{
			if (queue->node == lem->end && queue->flow == c)
			{
				vist[queue->node] = tmp->node;
				ft_free_queue(&lst->q);
				ft_memdel((void **)&lst);
				return (vist);
			}
			// if (vist[queue->node] == -1 && queue->flow == c && y == 0 &&
			// (node[tmp->node] == 0 || (node[tmp->node] == 1  && ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 && node[vist[tmp->node]] == 0 && node[queue->node] == 1  &&
			//  ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ||
			// ( node[vist[tmp->node]] == 1 && ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))
			
			if ( vist[queue->node] == -1 && queue->flow == c && y == 0 &&
				(node[tmp->node] == 0 || (node[tmp->node] == 1 && ((lem->adlist[vist[tmp->node]]->node_parent !=  tmp->node && node[vist[tmp->node]] == 0 && node[queue->node] == 1 &&
				lem->adlist[tmp->node]->node_parent ==  queue->node && tmp->flow == c) || (node[vist[tmp->node]] == 1 && lem->adlist[vist[tmp->node]]->node_parent ==  tmp->node )))))
			// if (vist[queue->node] == -1 && queue->flow == c &&
			// (node[tmp->node] == 0 || (node[tmp->node] == 1  && ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 && node[vist[tmp->node]] == 0 && node[queue->node] == 1  &&
			//  ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ||
			// ( node[vist[tmp->node]] == 1 && ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))

			// if (vist[queue->node] == -1 && queue->flow == c && y == 0 &&
			// 	(node[tmp->node] == 0 || (node[tmp->node] == 1 && ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 && node[vist[tmp->node]] == 0 && node[queue->node] == 1 &&
			// 														ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ||
			// 													   (node[vist[tmp->node]] == 1 && ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))
			// if (vist[queue->node] == -1 && queue->flow == c && y == 0 &&
			// (node[tmp->node] == 0 || (node[tmp->node] == 1  && ((ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 1 && node[vist[tmp->node]] == 0 && node[queue->node] == 1  &&
			//  ft_index_node(lem, tmp->node, queue->node, c, node) == 0) ||
			// ( node[vist[tmp->node]] == 1 && ft_index_node(lem, vist[tmp->node], tmp->node, c, node) == 0)))))
			{
				vist[queue->node] = tmp->node;
				ft_push_queue(&lst->last, queue->node);
				if (!(lst->q))
					lst->q = lst->last;
			}
			if (vist[queue->node] == -1 && queue->flow == c && y == 1 && node[tmp->node] == 0)
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
