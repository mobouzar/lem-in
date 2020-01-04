#include "lem_in.h"

static int ft_path_len(char *path)
{
	int i;
	int len;
	i = -1;
	len = 0;
	while (path[++i])
	{
		if (path[i] == '-')
			len++;
	}
	return (len > 0 ? len - 1 : len);
}

static t_print *ft_get_(char *tmp, char **tab_name)
{
	t_print *lst;

	if (!(lst = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	ft_memset((void *)lst, '\0', sizeof(t_print));
	lst->name = ft_strdup(tab_name[ft_atoi(tmp)]);
	//lst->nbr_bant = 0;
	lst->bant = 0;
	return (lst);
}

static t_print *ft_get_node_name(char *str, char **tab_name)
{
	t_print *init;
	t_print *lst;
	char **tmp;
	int i;

	init = NULL;
	i = ft_path_len(str) + 1;
	tmp = ft_strsplit(str, '-');
	lst = ft_get_(tmp[0], tab_name);
	lst->len_path = ft_path_len(str);
	init = lst;
	while (i > 0)
	{
		init->next = ft_get_(tmp[i], tab_name);
		init = init->next;
		i--;
	}
	return (lst);
}

static int ft_len_path(t_group *lst)
{
	t_group *tmp;
	int i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static t_print **ft_chang_path(t_group *g, int lenght, char **tab_name)
{
	t_print **init;
	int i;
	int j;

	i = 0;
	j = 0;
	int h = 0;
	int k = 0;
	init = NULL;
	if (!(init = (t_print **)malloc(sizeof(t_print *) * lenght)))
		return (NULL);
	ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
	while (g)
	{
		j = ft_path_len(g->grp);
		dprintf((h = open("/dev/ttys009", O_RDWR)), "path = %d		len = %d\n", i, j);
		close(h);
		k += j;
		init[i] = ft_get_node_name(g->grp, tab_name);
		init[i]->scor = j;
		g = g->next;
		i++;
	}
	//int h;
	dprintf((h = open("/dev/ttys007", O_RDWR)), "str = %d   int = %d \n", k, i);
	close(h);

	return (init);
}

void ft_print_(t_print ***init, int path, int path_2)
{
	t_print **g;
	t_print *q;
	t_print *m;
	t_lem_in *l;
	int i;

	g = *init;
	i = 0;
	l = getset(0);
	while (i < path)
	{
		q = g[i]->next->next;
		m = g[i]->next;
		while (q)
		{
			if (q && q->bant != 0)
			{
				ft_printf("L%d-%s ", q->bant, m->name);
				m->bant = q->bant;
				if (ft_strcmp(m->name, g[i]->next->name) == 0)
					l->nbr_ant_end++;
				q->bant = 0;
			}
			m = q;
			q = q->next;
		}
		if (l->nbr_ant_start < l->nbants && i < path_2)
		{
			(l->nbr_ant_start)++;
			ft_printf("L%d-%s ", (l->nbr_ant_start), m->name);
			m->bant = l->nbr_ant_start;
		}
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int ft_get_best_path_(t_group **lst, int ants)
{
	t_group *tmp;
	int scor;
	int j;
	int g1;

	scor = -1;
	j = 1;
	int k = 0;
	int len = 0;
	//int min = 0;
	tmp = *lst;
	int h;
	while (tmp)
	{
		len = ft_path_len(tmp->grp);
		k += len;

		//	close(h);
		g1 = ft_ceil(k + ants, j);
		if (getset(0)->nbants == ants)
		{
			dprintf((h = open("/dev/ttys011", O_RDWR)), "strg1 = %d   int = %d \n", g1, j);
			close(h);
		}
		if (g1 > scor && scor != -1) //=
			return (j - 1);
		if (scor == -1)
			scor = g1;
		scor = g1;
		j++;
		tmp = tmp->next;
	}
	return (j - 1);
}

void ft_print_instructoin()
{
	t_print **init;
	t_lem_in *lem;
	int i;
	int j;
	int h;
	int len_root;

	lem = getset(0);
	init = NULL;
	i = -1;
	lem->quit = 0;
	t_group *tmp = lem->g[0];
	j = 0;
	dprintf((h = open("/dev/ttys011", O_RDWR)), "\e[1;1H\e[2J");
	close(h);
	len_root = ft_len_path(lem->g[0]);
	init = ft_chang_path(lem->g[0], len_root, lem->rooms);
	i = ft_get_best_path_(&tmp, lem->nbants);
	// j = i;
	dprintf((h = open("/dev/ttys005", O_RDWR)), "\e[1;1H\e[2J");
	close(h);
	dprintf((h = open("/dev/ttys005", O_RDWR)), "pathii=%d \n", i);
	close(h);
	i = -1;
	//j = i;
	// while (lem->nbr_ant_end < lem->nbants)
	// {
	// 	j = ft_get_best_path_(&tmp, lem->nbants  - lem->nbr_ant_start);
	// 	if (i == -1)
	// 		i = j;
	// 	ft_print_(&init, i, j);

	// }
}
