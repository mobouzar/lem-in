
#include "../include/lem_in.h"

static int ft_path_len(char *path)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (path[++i])
		if (path[i] == '-')
			len++;
	return (len - 1);
}

int ft_count_group(t_group *lst, int *i)
{
	int len;

	len = 0;
	(*i) = 0;
	while (lst)
	{
		len += ft_path_len(lst->grp);
		lst = lst->next;
		(*i)++;
	}
	return (len);
}

// static void ft_free_group(t_group **lst)
// {
// 	t_group *tmp;
// 	t_group *tmp_2;

// 	tmp = *lst;
// 	while (tmp)
// 	{
// 		tmp_2 = tmp;
// 		tmp = tmp->next;
// 		ft_memdel((void **)&tmp_2);
// 	}
// 	*lst = NULL;
// }
static void ft_free_group(t_group **lst)
{
	if ((*lst) && (*lst)->next)
		ft_free_group(&(*lst)->next);
	ft_memdel((void **)lst);
}

int ft_get_best_scor(t_group **lst)
{
	t_group *tmp;
	int scor;
	int ants;
	int j;
	int k;
	int g1;

	scor = -1;
	j = 1;
	k = 0;
	ants = getset(0)->nbants;
	tmp = *lst;
	if ((*lst)->scor != -1 && (*lst)->len_g != -1)
		return ((*lst)->scor);
	while (tmp)
	{
		k += ft_path_len(tmp->grp);
		g1 = ft_ceil(k + ants, j);
		if (g1 > scor && scor != -1)
		{
			(*lst)->len_g = j - 1;
			(*lst)->scor = scor;
			return (scor);
		}
		scor = g1;
		j++;
		tmp = tmp->next;
	}
	return (scor);
}

void ft_get_best_grp(t_group ***lst, int nbants)
{
	int g1 = -1;
	int g2 = -1;
	(void)nbants;

	if (!(*lst)[1] || !(*lst[0]))
		return;
	g1 = ft_get_best_scor(&(*lst)[0]);
	g2 = ft_get_best_scor(&(*lst)[1]);
	if (g1 < g2)
	{
		getset(0)->quit = 0;
		return;
	}
	if (g1 > g2)
	{
		ft_free_group(&((*lst)[0]));
		(*lst)[0] = (*lst)[1];
		(*lst)[1] = NULL;
	}
	else
	{
		ft_free_group(&((*lst)[1]));
		(*lst)[1] = NULL;
	}
}
