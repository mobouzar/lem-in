#include "../include/lem_in.h"


static t_group *ft_get_group(char *group)
{
  t_group *g;

    if (!(g = (t_group *)malloc(sizeof(t_group))))
            return (NULL);
    ft_memset((void *)g, '\0', sizeof( t_group));
    g->grp = ft_strdup(group);
    g->len_g = ft_strlen(group);
    g->next = NULL;
    return (g);
}

static char *ft_convert_int_char(int *visit, int max)
{
    int i;
    char *str;

    str = ft_strdup(ft_itoa(max));
    i = max;
    while (i != 0)
    { 
        str = ft_strjoin_free( ft_strdup("-"), str);
        str = ft_strjoin_free(ft_itoa(visit[i]), str);  
        i = visit[i];
    }
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
         tmp = ft_strjoin_free(tmp, ft_strdup("-"));
        if (strstr(str, tmp))
        {
            //ft_free_tab(&room);
            ft_strdel(&tmp);
            return (1);
        }
        i++;
        ft_strdel(&tmp);
    }
   // ft_free_tab(&room);
    
    return (0);
}

static int ft_add_path(t_group **list, char *group, int i)
{
    t_group *tmp;
    t_group **lst;
    int     a;

   
    lst = list;
    tmp = lst[i];
    a = 0;
    while (tmp)
    {
        if (ft_check_path(tmp->grp, group))
        {
            a = 1;
        }
        tmp = tmp->next;
    }
    if (a == 0)
    {   
        tmp = ft_get_group(group);
        tmp->next = lst[i];
        list[i] = tmp;
        return (1);
    }
    return (0);
} 

void        ft_add_group(t_group ***lst, int *visit, int end , int i)
{
    t_group  **tmp;
    char     *group;

    tmp = *lst;
    // if (tmp[0])
    //     i = 1;
    group = ft_convert_int_char(visit, end);
    if (!tmp[i])
    {
       tmp[i] = ft_get_group(group);
        return ;
    }
   ft_add_path(*lst, group,  i);
}

// int main()
// {
//     t_group **tmp;
//     int         *visit;
//     char *group;
//     char *group2;

//     if (!(tmp = (t_group **)malloc(sizeof(t_group *) * (2))))
// 		return 0;
// 	ft_memset((void *)tmp, '\0', sizeof(t_group *) * (2));
//     if (!(visit = (int *)malloc(sizeof(int) * 8)))
// 		return 0;
// 	ft_memset((void *)tmp, '\0', (sizeof(int) * 8));
//     visit[0] =  1;
//     visit[2] = 0 ;
//     visit[5] = 2 ;
//     visit[7] = 5 ;

//  ft_add_group(&tmp, visit, 7, 1);

//       visit[0] =  1;
//      visit[1] = 0 ;
//       visit[4] =  1;
//        visit[5] =  4;
//         visit[2] = 5 ;
//          visit[3] =  2;
//           visit[6] = 3 ;
//           visit[7] = 6 ;
//  ft_add_group(&tmp, visit, 7 ,1);

//       visit[0] =  1;
//      visit[2] =  0;
//       visit[3] = 2 ;
//        visit[6] = 3 ;
//         visit[7] = 6 ;
// ft_add_group(&tmp, visit,  7, 0);

//       visit[0] = 1 ;
//      visit[1] = 0 ;
//       visit[4] =1  ;
//        visit[5] = 4 ;
//         visit[7] =  5;
//         ft_add_group(&tmp, visit,  7, 0);
//     int i;

//     i = 0;
//    ft_get_best_grp(&tmp, 10);//
//     t_group *lst;

//     while(i < 2)
//     {
//         lst = tmp[i];
//         while (lst)
//         {
//             ft_printf("i = %d  str = %s   ",i, lst->grp);
//             lst = lst->next;
//         }
//         ft_putchar('\n');
//          ft_putchar('\n');
//           ft_putchar('\n');
//         i++;

//     }
// //         group = ft_convert_int_char(visit, 7);
// // ft_putendl(group);
//     // ft_add_group(&tmp, visit, 0, 7);


//     //ft_printf("\n\nxx = %d\n", ft_check_path("0-1-4-5-2-3-6-7", "0-2-5-7"));

// }