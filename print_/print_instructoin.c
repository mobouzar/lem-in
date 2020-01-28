// #include "lem_in.h"

// static int ft_path_len(char *path)
// {
// 	int i;
// 	int len;
// 	i = -1;
// 	len = 0;
// 	while (path[++i])
// 	{
// 		if (path[i] == '-')
// 			len++;
// 	}
// 	return (len > 0 ? len - 1 : len);
// }

// static t_print *ft_get_(char *tmp, char **tab_name)
// {
// 	t_print *lst;

// 	if (!(lst = (t_print *)malloc(sizeof(t_print))))
// 		return (NULL);
// 	ft_memset((void *)lst, '\0', sizeof(t_print));
// 	lst->name = ft_strdup(tab_name[ft_atoi(tmp)]);
// 	lst->bant = 0;
// 	return (lst);
// }

// static t_print *ft_get_node_name(char *str, char **tab_name)
// {
// 	t_print *init;
// 	t_print *lst;
// 	char **tmp;
// 	int i;

// 	init = NULL;
// 	i = ft_path_len(str) + 1;
// 	tmp = ft_strsplit(str, '-');
// 	lst = ft_get_(tmp[0], tab_name);
// 	lst->len_path = ft_path_len(str);
// 	init = lst;
// 	while (i > 0)
// 	{
// 		init->next = ft_get_(tmp[i], tab_name);
// 		init = init->next;
// 		i--;
// 	}
// 	return (lst);
// }

// static t_print **ft_get_ants_start(t_print ***lst, t_group *g, int lenght, char **tab_name)
// {
// 	t_print **init;
// 	t_lem_in *l;
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	int k = 0;
// 	init = *lst;
// 	l = getset(0);
// 	l->nbr = l->nbants;
// 	ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
// 	while (g && i < lenght)
// 	{
// 		j = g->len_g;
// 		k += j;
// 		init[i] = ft_get_node_name(g->grp, tab_name);
// 		init[i]->len_path = g->len_g;
// 		if (l->len - j >= 0)
// 			init[i]->scor = l->len - j;
// 		if (l->len - j >= 0)
// 			l->nbr -= l->len - j;
// 		g = g->next;
// 		i++;
// 	}
// 	return (init);
// }
// static t_print **ft_chang_path(t_group *g, int lenght, char **tab_name)
// {
// 	t_print **init;
// 	t_lem_in *l;
// 	int i;

// 	i = 0;
// 	init = NULL;
// 	if (!(init = (t_print **)malloc(sizeof(t_print *) * lenght)))
// 		return (NULL);
// 	init = ft_get_ants_start(&init, g, lenght, tab_name);
// 	l = getset(0);
// 	while (l->nbr > 0)
// 	{
// 		i = 0;
// 		while (i < lenght && l->nbr)
// 		{
// 			init[i]->scor++;
// 			l->nbr--;
// 			i++;
// 		}
// 	}
// 	return (init);
// }


// // static t_print **ft_chang_path(t_group *g, int lenght, char **tab_name)
// // {
// // 	t_print **init;
// // 	t_lem_in *l;
// // 	int i;
// // 	int j;

// // 	i = 0;
// // 	j = 0;
// // 	//int h = 0;
// // 	int k = 0;
// // 	init = NULL;
// // 	l = getset(0);
// // 	l->nbr = l->nbants;
// // 	//printf("len = |%d|			nbr=|%d|\n",l->len , l->nbr);
// // 	if (!(init = (t_print **)malloc(sizeof(t_print *) * lenght)))
// // 		return (NULL);
// // 	ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
// // 	while (g && i < lenght)
// // 	{
// // 		j = g->len_g;
// // 		// 	dprintf((h = open("/dev/ttys013", O_RDWR)), "path = %d		len = %d\n", i, j);
// // 		// close(h);
// // 		//j = ft_path_len(g->grp);
		
// // 		// dprintf((h = open("/dev/ttys009", O_RDWR)), "path = %d		len = %d\n", i, j);
// // 		// close(h);
// // 		k += j;
// // 		init[i] = ft_get_node_name(g->grp, tab_name);
// // 		init[i]->len_path = g->len_g;
// // 		if (l->len - j >= 0)
// // 			init[i]->scor = l->len - j;
// // 		if (l->len - j >= 0)
// // 			l->nbr -= l->len - j;
// // 		g = g->next;
// // 		i++;
// // 	}
// // 	i = 0;
// // 	while (l->nbr > 0)
// // 	{
// // 		i = 0;
// // 		while (i < lenght && l->nbr)
// // 		{
// // 				//dprintf((h = open("/dev/ttys008", O_RDWR)), "i == %d path = %d		cor=%d 		nbr= %d    fare9=%d     len=%d		nbants=%d\n",
// // 				//i,init[i]->len_path, init[i]->scor, l->nbr, init[i]->scor +init[i]->len_path , l->len, l->nbants);
// // 				//	close(h);
// // 			init[i]->scor++;
// // 			l->nbr--;
// // 			i++;

// // 		}
// // 	}
// // 	//int h;
// // 	// dprintf((h = open("/dev/ttys007", O_RDWR)), "str = %d   int = %d \n", k, i);
// // 	// close(h);

// // 	return (init);
// // }

// static 		void ft_affich(t_print **g, t_print *q, t_print *m, int i)
// {
// 	t_lem_in *l;

// 	l = getset(0);
// 	while (q)
// 	{
// 		if (q && q->bant != 0)
// 		{
// 			ft_printf("L%d-%s ", q->bant, m->name);
// 			m->bant = q->bant;
// 			if (ft_strcmp(m->name, g[i]->next->name) == 0)
// 				l->nbr_ant_end++;
// 			q->bant = 0;
// 		}
// 		m = q;
// 		q = q->next;
// 	}
// 	if (l->nbr_ant_start < l->nbants && g[i]->scor > 0)
// 	{
// 		(l->nbr_ant_start)++;
// 		ft_printf("L%d-%s ", (l->nbr_ant_start), m->name);
// 		m->bant = l->nbr_ant_start;
// 		g[i]->scor--;
// 	}
// }
// void ft_print_(t_print ***init, int path)
// {
// 	t_print **g;
// 	t_print *q;
// 	t_print *m;
// 	t_lem_in *l;
// 	int i;

// 	g = *init;
// 	i = 0;
// 	l = getset(0);
// 	while (i < path)
// 	{
// 		q = g[i]->next->next;
// 		m = g[i]->next;
// 		ft_affich(g, q, m, i);
// 		i++;
// 	}
// 	ft_putchar_fd('\n', 1);
// }

// int ft_get_best_path_(t_group *tmp, int ants)
// {
// 	int scor;
// 	int j;
// 	int g1;
// 	int k;
// 	int len;

// 	scor = -1;
// 	j = 0;
// 	k = 0;
// 	len = 0;
// 	while (tmp && ++j)
// 	{
// 		len = ft_path_len(tmp->grp);
// 		tmp->len_g = len;
// 		k += len;
// 		g1 = ft_ceil(k + ants, j);
// 	int h;dprintf((h=open("/dev/ttys003",O_RDWR)),"g1= %d			g2 = %d	\n",g1, 0); close(h);

// 		if (g1 > scor && scor != -1)
// 			return (j);
// 		scor = g1;
// 		getset(0)->len = len;
// 		tmp = tmp->next;
// 	}
// 	return (j);
// }

// void ft_print_instructoin()
// {
// 	t_print **init;
// 	t_lem_in *lem;
// 	t_group *tmp;
// 	int i;

// 	lem = getset(0);
// 	init = NULL;

// 	lem->quit = 0;
// 	tmp = lem->g[0];
// 	i = ft_get_best_path_(tmp, lem->nbants);
// 	init = ft_chang_path(lem->g[0], i, lem->rooms);
// 	while (lem->nbr_ant_end < lem->nbants)
// 		ft_print_(&init, i);
// }

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

 int ft_len_path(t_group **lst)
{
	t_group *tmp;
	int i;
	int h;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		i++;
		dprintf((h = open("vv", O_RDWR | O_APPEND)), "|%s|\n",tmp->grp);close(h);
		tmp = tmp->next;
	}
	return (i);
}

// static t_print **ft_chang_path(t_group *g, int lenght, char **tab_name)
// {
// 	t_print **init;
// 	t_lem_in *l;
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	//int h = 0;
// 	int k = 0;
// 	init = NULL;
// 	l = getset(0);
// 	l->nbr = l->nbants;
// 	//printf("len = |%d|			nbr=|%d|\n",l->len , l->nbr);
// 	if (!(init = (t_print **)malloc(sizeof(t_print *) * lenght)))
// 		return (NULL);
// 	ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
// 	while (g && i < lenght)
// 	{
// 		j = g->len_g;
// 		// 	dprintf((h = open("/dev/ttys013", O_RDWR)), "path = %d		len = %d\n", i, j);
// 		// close(h);
// 		//j = ft_path_len(g->grp);
		
// 		// dprintf((h = open("/dev/ttys009", O_RDWR)), "path = %d		len = %d\n", i, j);
// 		// close(h);
// 		k += j;
// 		init[i] = ft_get_node_name(g->grp, tab_name);
// 		init[i]->len_path = g->len_g;
// 		if (l->len - j >= 0)
// 			init[i]->scor = l->len - j;
// 		if (l->len - j >= 0)
// 			l->nbr -= l->len - j;
// 		g = g->next;
// 		i++;
// 	}
// 	i = 0;
// 	while (l->nbr > 0)
// 	{
// 		i = 0;
// 		while (i < lenght && l->nbr)
// 		{
// 				//dprintf((h = open("/dev/ttys008", O_RDWR)), "i == %d path = %d		cor=%d 		nbr= %d    fare9=%d     len=%d		nbants=%d\n",
// 				//i,init[i]->len_path, init[i]->scor, l->nbr, init[i]->scor +init[i]->len_path , l->len, l->nbants);
// 				//	close(h);
// 			init[i]->scor++;
// 			l->nbr--;
// 			i++;

// 		}
// 	}
// 	//int h;
// 	// dprintf((h = open("/dev/ttys007", O_RDWR)), "str = %d   int = %d \n", k, i);
// 	// close(h);

// 	return (init);
// }

void ft_print_(t_print ***init, int path, int path_2)
{
	t_print **g;
	t_print *q;
	t_print *m;
	t_lem_in *l;
	int i;
	//int h = 0;

	g = *init;
	i = 0;
	(void)path_2;
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
			//dprintf((h = open("/dev/ttys012", O_RDWR)),"i=%d		scor = |%d|\n",i	,g[i]->scor);close(h);
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

	i = 0;
	j = 0;
	int k = 0;
	init = *lst;
	l = getset(0);
	l->nbr = l->nbants;
	ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
	while (g && i < lenght)
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
		i++;
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
		i = 0;
		while (i < lenght && l->nbr)
		{
			init[i]->scor++;
			l->nbr--;
			i++;
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
	//int min = 0;
	int h;
	tmp = *lst;
	//return (tmp->len_g);////
	// int h;
	dprintf((h = open("/dev/ttys003", O_RDWR)), "scor = %d   len = %d \n", tmp->scor, tmp->len_g);
			close(h);
	while (tmp)
	{
		//dprintf((h = open("x", O_RDWR | O_APPEND)), "|%s|\n",tmp->grp);close(h);
		len = ft_path_len(tmp->grp);
		tmp->len_g = len;
		
		//printf("xx=%d\n", getset(0)->len);
		k += len;

		//	close(h);
		g1 = ft_ceil(k + ants, j);
		// if (getset(0)->nbants == ants)
		// {
		// 	dprintf((h = open("/dev/ttys002", O_RDWR)), "strg1 = %d   int = %d \n", g1, j);
		// 	close(h);
		// }
		if (g1 >= scor && scor != -1) //=
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

void ft_print_instructoin()
{
	t_print **init;
	t_lem_in *lem;
	int i;
	int j;
	//int h;
	int len_root;

	lem = getset(0);
	init = NULL;
	i = -1;
	//int h;
	int k = 0;
	lem->quit = 0;
	t_group *tmp = lem->g[0];
	j = 0;
	//dprintf((h = open("/dev/ttys002", O_RDWR)), "\e[1;1H\e[2J");
	//close(h);
	// k = ft_len_path(&(lem->g[0]));
	// int h;
	// dprintf((h = open("/dev/ttys004", O_RDWR)), "\e[1;1H\e[2J");
	// close(h);
	// dprintf((h = open("/dev/ttys001", O_RDWR)), "kk=%d \n", k);
	// close(h);
	i = ft_get_best_path_(&tmp, lem->nbants);
	k = i;
	int h;
	dprintf((h = open("/dev/ttys003", O_RDWR)), "kk=%d \n", k);
	close(h);
	len_root = i;
	//ft_len_path(lem->g[0], &k);
	init = ft_chang_path(lem->g[0], len_root, lem->rooms);
	
	
	//i = ft_get_best_path_(&tmp, lem->nbants  - lem->nbr_ant_start);
	//i = -1;
	j = i;
	while (lem->nbr_ant_end < lem->nbants)
	{
		
		ft_print_(&init, i, i);

	}
 }

