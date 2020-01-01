#include "include/lem_in.h"

t_lem_in * getset(t_lem_in *l)
{
	static t_lem_in *g;

	if (l)
		g = l;
	return (g);
}

void ft_get_path_(t_lem_in *lst, int *path, int i, int index)
{
	if (i == lst->start || path == NULL)
		return;

	ft_get_path_(lst, path, path[i], index); //
	//ft_printf("%s ==> ", lst->rooms[path[i]]);
	ft_index_path(lst, i, path[i],index);
	ft_index_path_cap(lst, path[i], i,index);
	ft_index_path(lst,  path[i], i,index);
}

int main(void)
{
	int *path;
	t_lem_in l;
	t_map *map;
	int i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	ft_memset((void *)map, '\0', sizeof(t_map));
	read_data(map, &l);
	path = NULL;
	l.quit = 1;
	 l.nbr_ant_start = 0;
	i  = 0;
	getset(&l);
	while (i < 100)
	{
		while ((path = _bfs(&l, i)))
		{
			if (i == 0)
				ft_add_group(&(l.g), path, l.end,0, l.start);
			else
				ft_add_group(&(l.g), path, l.end,1, l.start);
			ft_get_path_(&l, path, l.end, i);
			path = NULL;
		}
		ft_get_best_grp(&(l.g), l.nbants);
		// if (getset(0)->quit == 0)
		// 	break ;
		i++;
	}
	//getset(&l);
	ft_print_instructoin();
}
