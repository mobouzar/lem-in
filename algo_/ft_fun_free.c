#include "../include/lem_in.h"


void    ft_free_tab(char ***tab)
{
    int i;
    char **str;

    i = 0;
    str = *tab;
    while (str[i])
    {
        ft_strdel(&str[i]);
        i++;
    }
    free(str);
}

void		ft_free_queue(t_queue **lst)
{
	t_queue	*tmp;

	if ((*lst))
	{
		while ((*lst))
		{
			tmp = (*lst);
			(*lst) = (*lst)->next;
			ft_memdel((void	**)&tmp);
		}
	}
}