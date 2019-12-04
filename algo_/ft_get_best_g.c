#include "lem_in.h"

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
static int ft_count_group(t_group *lst, int *i)
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

static void ft_free_group(t_group **lst)
{
    t_group *tmp;
    t_group *tmp_2;

    tmp = *lst;
    while (tmp)
    {
        tmp_2 = tmp;
        tmp = tmp->next;
        ft_memdel((void **)&tmp_2);
    }
    *lst = NULL;
}

void ft_get_best_grp(t_group ***lst, int nbants)
{
    int g1;
    int g2;
    int le_1;
    int le_2;

    g1 = ft_count_group((*lst)[0], &le_1);
    g2 = ft_count_group((*lst)[1], &le_2);
    g1 = ft_ceil(g1 * nbants, le_1);
    g2 = ft_ceil(g2 * nbants, le_2);
    if (g1 < g2)
    {
        ft_free_group(&((*lst)[1]));
        (*lst)[1] = NULL;
    }
    else
    {
        ft_free_group(&((*lst)[0]));
        (*lst)[0] = (*lst)[1];
        (*lst)[1] = NULL;
    }
}
