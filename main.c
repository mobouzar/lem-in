#include "include/lem_in.h"

t_lem_in * getset(t_lem_in *l)
{
	static t_lem_in *g;

	if (l)
		g = l;
	return (g);
}

void ft_get_path_(t_lem_in *lst, int *path, int i, int index, int *node)
{
	if (i == lst->start || path == NULL)
		return;

	ft_get_path_(lst, path, path[i], index, node);
	if (path[i] != lst->start && path[i] != lst->end)
	{
	 	node[path[i]] = 1;
		///ft_printf("|%s| ==> \n", lst->rooms[path[i]]);
	}
//	ft_printf("%s ==> ", lst->rooms[path[i]]);
	ft_index_path(lst, i, path[i],index);
}

// void			intersection_()
int main(void)
{
	int *path;
	t_lem_in l;
	t_map *map;
	int *node_visit;
	int i;

	i = 0;
	node_visit = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	ft_memset((void *)&l, '\0', sizeof(t_lem_in));
	ft_memset((void *)map, '\0', sizeof(t_map));
	read_data(map, &l);
	node_visit = (int *)malloc(sizeof(int) * (l.nbrooms));
	path = NULL;
	l.quit = 1;
	 l.nbr_ant_start = 0;
	i  = 0;
	getset(&l);
	while (1)
	{
		ft_memset((void *)node_visit, 0,sizeof(int) * l.nbrooms); 
		while ((path = _bfs(&l, i % 2 , node_visit)))
		{
			l.index = i % 2;
			if (i == 0)
				ft_add_group(&(l.g), path, l.end,0, l.start);
			else
				ft_add_group(&(l.g), path, l.end,1, l.start);
			ft_get_path_(&l, path, l.end, i % 2, node_visit);
			//ft_putstr(l.rooms[l.end]);
			//ft_putchar('\n');
			path = NULL;
		}
		ft_putendl("----------------------------------");
		ft_get_best_grp(&(l.g), l.nbants);
		if (getset(0)->quit == 0)
			break ;
		i++;
	}
	ft_print_instructoin();
}
