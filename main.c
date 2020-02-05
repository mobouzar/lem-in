#include "include/lem_in.h"

void print_data(t_map *data)
{
	while (data->next)
	{
		ft_printf("%s\n", data->data);
		data = data->next;
	}
	ft_printf("\n");
}

t_lem_in *getset(t_lem_in *l)
{
	static t_lem_in *g;

	if (l)
		g = l;
	return (g);
}

void ft_get_path_(t_lem_in *lst, int *path, int index, int *node)
{
	int i;
	int min;

	if (lst->end == lst->start || path == NULL)
		return;
	i = lst->end;
	min = lst->start;
	while (i != min)
	{
		if (path[i] != lst->start && path[i] != lst->end)
			node[path[i]] = 1;
		lst->adlist[i]->node_parent = path[i];
		ft_index_path(lst, i, path[i], index);
		i = path[i];
	}
}

void ft_get_path_22(t_lem_in *lst, int *path, int *node)
{
	int i;

	int min;
	if (lst->end == lst->start || path == NULL)
		return;
	i = lst->end;
	min = lst->start;
	while (i != min)
	{
		if (path[i] != lst->start && path[i] != lst->end)
			node[path[i]] = 1;
		i = path[i];
	}
}

int main(void)
{
	int *path;
	t_lem_in l;
	t_map *map;
	t_map *head;
	int *node_visit;
	int *node_visit22;
	int i;

	i = 0;
	node_visit = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	head = map;
	ft_memset((void *)&l, '\0', sizeof(t_lem_in));
	ft_memset((void *)map, '\0', sizeof(t_map));
	read_data(map, &l);
	node_visit = (int *)malloc(sizeof(int) * ((l.nbrooms)));
	node_visit22 = (int *)malloc(sizeof(int) * ((l.nbrooms)));
	path = NULL;
	l.quit = 1;
	int h;
	(void)h;
	int j = 0;
	getset(&l);
	ft_memset((void *)node_visit, 0, sizeof(int) * l.nbrooms);
	while ((path = _bfs(&l, 0, node_visit, 0)))
	{
		ft_get_path_(&l, path, 0, node_visit);
		ft_memdel((void **)&path);
		ft_memset((void *)node_visit22, 0, sizeof(int) * l.nbrooms);
		while ((path = _bfs(&l, 1, node_visit22, 1)))
		{
			ft_get_path_22(&l, path, node_visit22);
			if (j == 0)
				ft_add_group(&(l.g), path, l.end, 0, l.start);
			else
				ft_add_group(&(l.g), path, l.end, 1, l.start);
			if (path && path[l.end] == l.start)
				break;

			ft_memdel((void **)&path);
		}
		if (path && path[l.end] == l.start)
		{
			ft_memdel((void **)&path);
			ft_memdel((void **)&node_visit);
			ft_memdel((void **)&node_visit22);
			break;
		}
		j++;
		ft_get_best_grp(&(l.g), l.nbants);
		if (getset(0)->quit == 0)
			break;
	}
	if (!(l.g[0]))
	{
		ft_memdel((void **)&node_visit);
		ft_memdel((void **)&node_visit22);
		ft_putendl("not path");
		return 0;
	}
	ft_memdel((void **)&node_visit);
	ft_memdel((void **)&node_visit22);
	print_data(head);
	ft_print_instructoin();
}
