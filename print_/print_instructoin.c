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
static t_print *ft_get_(char *tmp, char **tab_name)
{
    t_print *lst;

    if (!(lst = (t_print *)malloc(sizeof(t_print))))
        return (NULL);
    ft_memset((void *)lst, '\0', sizeof(t_print));
    lst->name = ft_strdup(tab_name[ft_atoi(tmp)]);
    lst->nbr_bant = 0;
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
    lst->len_path = ft_path_len(str);//printf("i= %d          str = %s  \n\n",ft_path_len(str), str);
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

    i = 0;
    init = NULL;
    if (!(init = (t_print **)malloc(sizeof(t_print *) * lenght)))
        return (NULL);
    ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
    while (g)
    {
        init[i] = ft_get_node_name(g->grp, tab_name);
        g = g->next;
        i++;
    }
    return (init);
}
static int ft_get_root_(t_print **init, int len_root, int ant)
{
    int i;
    int j;
    int instructoin;

    i = 1;
    j = 0;
    instructoin = (ant + init[0]->len_path);
    printf("instructoin= %d          nbr_ant = %d     len = %d  str = %s\n\n",instructoin, ant, init[i]->len_path ,init[i]->next->next->name);
    while (i < len_root)
    {

        if (instructoin < (ant + init[i]->len_path))
        {
            j++;
            instructoin += (ant + init[i]->len_path);
        }
        printf("22instructoin= %d          nbr_ant = %d     len = %d  str = %s\n\n",instructoin, ant, init[i]->len_path ,init[i]->next->next->name);
        i++;
    }
    return (j);
}
static int ft_print_(t_print ***init, int path, int len_root)
{
    t_print **g;
    t_print *q;
    // t_print *k;
     t_print *m;
    t_lem_in *l;
    int i;

    g = *init;
    i = 0;
    l = getset(0);
    (void)len_root;
    while (i <= path)
    {
        q = g[i]->next->next;
        m =  g[i]->next;
        while (q)
        {
            if (q && q->bant != 0)
            {
                ft_printf("L%d-%s ", q->bant, m->name);
                m->bant = q->bant;
                if (ft_strcmp(m->name,g[i]->next->name) == 0)
                     l->nbr_ant_end++;
                q->bant = 0;
            }
            m = q;
            q = q->next;
        }
        if (l->nbr_ant_start <= l->nbants)
        {
            ft_printf("L%d-%s ", (l->nbr_ant_start), m->name);
            m->bant = l->nbr_ant_start;
            (l->nbr_ant_start)++;
        }
        i++;
    }
    getset(l);
    ft_putchar_fd('\n', 1);
    return (l->nbr_ant_end);
}

void ft_print_instructoin()
{
    t_print **init;
    //t_print *g;
    t_lem_in *lem;
    int i = 0;
    int len_root;

    lem = getset(0);
    init = NULL;

    len_root = ft_len_path(lem->g[0]);

    init = ft_chang_path(lem->g[0], len_root, lem->rooms);
    // while (i < 2)
    // {
    //     g = init[i];
    //     while (g)
    //     {
    //         ft_printf("==>%s", g->name);
    //         g = g->next;
    //     }
    //     ft_putchar('\n');
    //     i++;
    // }
    int j;
    
     i = ft_get_root_(init, len_root,lem->nbants);
    printf("vv = %d\n", len_root - 1);
    j = 0;
    i = len_root - 1;
    while (j <= lem->nbants)
    {
     
         
        j  = ft_print_(&init, i, len_root);
        j++;
    }
}
