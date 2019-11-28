#include "lem_in.h"

static t_path *ft_get_path(char *group)
{
    t_path *g;

    if (!(g = (t_path *)malloc(sizeof(t_path))))
            return ;
    ft_memset((void *)&g, '\0', sizeof( t_path));
    g->grp = ft_strdup(group);
    g->len_g = ft_strlen(group);
    return (g);
}

static char *ft_convert_int_char(int *visit, int max)
{
    int i;
    char *str;

    str = ft_strdup("0-");
    i = max;
    while (i != 0)
    {
        str = ft_strjoin_free(str, ft_itoa(visit[i]));
        str = ft_strjoin_free(str, ft_strdup("-"));
        i = visit[i];
    }
    str = ft_strjoin_free(str, ft_itoa(max));
    return (str);
}

static int  ft_check_path(char *str, char *g)
{
    char **room;
    char  *tmp;
    int     i;

    i = 0;
    tmp = ft_strnew(0);
    room = ft_strsplit(g, '-');
    while (room[i])
    {
        tmp = ft_strjoin("-", room[i]);
        tmp = ft_strjoin_free(tmp, "-");
        if (ft_strstr(str, tmp))
        {
            ft_free_tab(&room);
            ft_strdel(&tmp);
            return (0);
        }
    }
    ft_free_tab(&room);
    ft_strdel(&tmp);
    return (1);
}

static int ft_add_path(t_path **lst, char *group)
{
    t_path *tmp;
    int     a;

    tmp = *lst;
    a = 0;
    while (tmp)
    {
        if (ft_check_path(tmp->grp, group))
            a = 1;
        tmp = tmp->next;
    }
    if (a == 0)
    {
        tmp = ft_get_path(group);
        return (1);
    }
    return (0);
} 

void        ft_add_group(t_group **lst, char *group)
{
    t_group *tmp;
    int a;

    tmp = *lst;
    a = 0;
    if (!(*lst))
    {
        if (!((*lst) = (t_group *)malloc(sizeof(t_group))))
            return ;
        (*lst)->avnc = ft_get_path(group);
        (*lst)->next = NULL;
        return ;
    }
    while (tmp)
    {
        if (ft_add_path(&tmp->avnc, group))
            a = 1;
        tmp = tmp->next;
    }
    if (a == 0)
        return ;
    if (!(tmp = (t_group *)malloc(sizeof(t_group))))
        return ;
    tmp->avnc = ft_get_path(group);
    tmp->next = NULL;
}