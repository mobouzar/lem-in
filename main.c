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

void ft_get_path_22(t_lem_in *lst, int **path, int *node)
{
	int i;

	int min;
	if (lst->end == lst->start || (*path) == NULL)
		return;
	i = lst->end;
	min = lst->start;
	while (i != min)
	{
		if ((*path)[i] != lst->start && (*path)[i] != lst->end)
			node[(*path)[i]] = 1;
		i = (*path)[i];
	}
}

void ft_init_bufer(t_lem_in *l, int **node_visit, int **node_visit22)
{
	if (!((*node_visit) = (int *)malloc(sizeof(int) * ((l->nbrooms)))))
		return;
	if (!(*node_visit22 = (int *)malloc(sizeof(int) * ((l->nbrooms)))))
		return;
	ft_memset((void *)(*node_visit), 0, sizeof(int) * l->nbrooms);
	ft_memset((void *)(*node_visit22), 0, sizeof(int) * l->nbrooms);
}

void ft_free_buffer(int **node_visit, int **node_visit22, int **path)
{
	ft_memdel((void **)path);
	ft_memdel((void **)node_visit);
	ft_memdel((void **)node_visit22);
}

int ft_get_paths(t_lem_in *l)
{
	int *node_visit;
	int *node_visit22;
	int *path;

	path = NULL;
	ft_init_bufer(l, &node_visit, &node_visit22);
	while ((path = ft_bfs(l, 0, node_visit, 0)))
	{
		ft_get_path_(&path, 0, node_visit, &node_visit22);
		while ((path = ft_bfs(l, 1, node_visit22, 1)))
		{
			ft_get_path_22(l, &path, node_visit22);
			ft_add_group(&(l->g), path, 1);
			ft_memdel((void **)&path);
			if (path && path[l->end] == l->start)
			{
				ft_free_buffer(&node_visit, &node_visit22, &path);
				return (1);
			}
		}
		ft_get_best_grp(&(l->g), l->nbants);
	}
	ft_free_buffer(&node_visit, &node_visit22, NULL);
	return (0);
}

void ft_mangement_instructoin(t_lem_in *l, t_map *head)
{
	if (ft_get_paths(l))
	{
		print_data(head);
		while (l->nbr_ant_start++ < l->nbants)
			ft_printf("L%d-%s ", (l->nbr_ant_start), l->rooms[l->end]);
		ft_putchar('\n');
	}
	else
	{
		if (!(l->g[0]))
			ft_putendl("not path");
		else
		{
			print_data(head);
			ft_print_instructoin();
		}
	}
}
int main(void)
{
	t_lem_in l;
	t_map *map;
	t_map *head;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (1);
	head = map;
	ft_memset((void *)&l, '\0', sizeof(t_lem_in));
	ft_memset((void *)map, '\0', sizeof(t_map));
	read_data(map, &l);
	getset(&l);
	ft_mangement_instructoin(&l, head);
	return (0);
}
