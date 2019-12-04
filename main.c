#include "lem_in.h"

static void ft_get_path_(t_lem_in *lst, int *path, int i)
{
	//ft_putendl("yyyyyyyy");
	if (i == lst->start || path == NULL)
		return;

	ft_get_path_(lst, path, path[i]); //
	ft_printf("%d ==> ", path[i]);
	ft_index_path(lst, i, path[i]);
	//ft_index_path_cap(lst, path[i], i);
	//ft_index_path(lst,  path[i], i);
}
int main()
{

	int *path;
	t_lem_in l;
	t_map *map;
	t_map *head;
	int   i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	ft_memset((void *)map, '\0', sizeof(t_map));
	head = map;
	read_data(map, &l);

	path = NULL;
	printf("\n\nstrat = %d			end = %d\n", l.start, l.end);
	while (i < 100)
	{
		while ((path = _bfs(&l, i)))
		{
			ft_get_path_(&l, path, l.end);
			if (path)
			{
				ft_putnbr(l.end);
				ft_printf("\n\n");
			}
			path = NULL;
		}
		i++;
		ft_putendl("------------");
	}
}