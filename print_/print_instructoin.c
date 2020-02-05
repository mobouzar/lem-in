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
	lst->bant = 0;
	lst->next = NULL;
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
		init->next = NULL;
		i--;
	}
	ft_free_tab(&tmp);/////
	return (lst);
}

 int ft_len_path(t_group **lst)
{
	t_group *tmp;
	int i;
	

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void ft_print_(t_print ***init, int path)
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
		if (l->nbr_ant_start < l->nbants && g[i]->scor > 0 )
		{
			
			(l->nbr_ant_start)++;
			ft_printf("L%d-%s ", (l->nbr_ant_start), m->name);
			m->bant = l->nbr_ant_start;
			g[i]->scor--;	
		}
		i++;
	}
	ft_putchar_fd('\n', 1);
}

static t_print **ft_get_ants_start(t_print ***lst, t_group *g, int lenght, char **tab_name)
{
	t_print **init;
	t_lem_in *l;
	int i;
	int j;	
	int k ;

	i = -1;
	j = 0;
	k = 0;
	init = *lst;
	l = getset(0);
	l->nbr = l->nbants;
	ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
	while (g && ++i < lenght)
	{
		j = g->len_g;
		k += j;
		init[i] = ft_get_node_name(g->grp, tab_name);
		init[i]->len_path = g->len_g;
		if (l->len - j >= 0)
			init[i]->scor = l->len - j;
		if (l->len - j >= 0)
			l->nbr -= l->len - j;
		g = g->next;
	}
	return (init);
}

static t_print **ft_chang_path(t_group *g, int lenght, char **tab_name)
{
	t_print **init;
	t_lem_in *l;
	int i;

	i = 0;
	init = NULL;
	if (!(init = (t_print **)malloc(sizeof(t_print *) * lenght)))
		return (NULL);
	init = ft_get_ants_start(&init, g, lenght, tab_name);
	l = getset(0);
	while (l->nbr > 0)
	{
		i = -1;
		while (++i < lenght && l->nbr)
		{
			init[i]->scor++;
			l->nbr--;
		}
	}
	return (init);
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
	tmp = *lst;
	while (tmp)
	{
		len = ft_path_len(tmp->grp);
		tmp->len_g = len;
		k += len;
		g1 = ft_ceil(k + ants, j);
		if (g1 >= scor && scor != -1)
			return (j - 1);
		if (scor == -1)
			scor = g1;
		scor = g1;
		getset(0)->len = len;
		j++;
		tmp = tmp->next;
	}
	return (j - 1);
}

void		ft_free_init_(t_print **init)
{
	 if ((*init) && (*init)->next)
	 	ft_free_init_(&(*init)->next);
	ft_strdel(&(*init)->name);
	ft_memdel((void **)init);
}

void	ft_free_init(t_print ***init, int j)
{
	t_lem_in *p;
	int i;

	p = getset(0);
	i = 0;
	while ((*init)[i] && i < j)
	{
		ft_free_init_(&(*init)[i]);
		i++;
	}
	ft_memdel((void **)init);
}


void ft_print_instructoin(void)
{
	t_group *tmp;
	t_print **init;
	t_lem_in *lem;
	int i;

	lem = getset(0);
	tmp = lem->g[0];
	init = NULL;
	i = -1;
	lem->quit = 0;
	i = ft_get_best_path_(&tmp, lem->nbants);
	init = ft_chang_path(lem->g[0], i, lem->rooms);
	while (lem->nbr_ant_end < lem->nbants)
	{	
		ft_print_(&init, i);
	}
	ft_free_init(&init, i);
 }

