#include "include/lem_in.h"

t_lem_in * getset(t_lem_in *l)
{
	static t_lem_in *g;

	if (l)
		g = l;
	return (g);
}
static void ft_get_path_(t_lem_in *lst, int *path, int i)
{
	//ft_putendl("yyyyyyyy");
	if (i == lst->start || path == NULL)
		return;

	ft_get_path_(lst, path, path[i]); //
	ft_printf("%s ==> ", lst->rooms[path[i]]);
	ft_index_path(lst, i, path[i]);
	//ft_index_path_cap(lst, path[i], i);
	//ft_index_path(lst,  path[i], i);
}
int main()
{

	int *path;
	t_lem_in l;
	t_map *map;
//	t_map *head;
	int i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	ft_memset((void *)map, '\0', sizeof(t_map));
	//head = map;
	read_data(map, &l);

	path = NULL;
	l.quit = 1;
	 l.nbr_ant_start = 1;
	i  = 0;
	// printf("\n\nstrat = %d			end = %d\n", l.start, l.end);
	while (l.quit < 80)
	{
		while ((path = _bfs(&l, i)))
		{
			if (i == 0)
				ft_add_group(&(l.g), path, l.end,0, l.start);
			else
				ft_add_group(&(l.g), path, l.end,1, l.start);

			ft_get_path_(&l, path, l.end);
			if (path)
			{
				
				//ft_putnbr(l.end);
				ft_printf("%s\n", l.rooms[l.end]);
			}
			path = NULL;
		}
		ft_get_best_grp(&(l.g), l.nbants);
		printf("\n------------------\n");
		(l.quit)++;
		i++;
	}
	getset(&l);
	 ft_print_instructoin();
	
	// t_group *lst;
	// i = 0;

	// while (i < 2)
	// {
	// 	lst = (l.g)[i];
	// 	while (lst)
	// 	{
	// 		ft_printf("i = %d  str = %s   \n", i, lst->grp);
	// 		lst = lst->next;
	// 	}
	// 	ft_putchar('\n');
	// 	ft_putchar('\n');
	// 	ft_putchar('\n');
	// 	i++;
	// }
}