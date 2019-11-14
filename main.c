/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:49 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/14 14:42:53 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_data(t_lem_in *l)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	l->nbants = -1;
	get_next_line(0, &line);
	len = ft_strlen(line);
	while (len <= 10 && line[i])
		if (ft_isdigit(line[i]))
			i++;
		else
			return (0);
	if (len <= 10)
		l->nbants = ft_atoi(line);
	if (l->nbants == 0 && len > 10)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_lem_in	l;

	parse_data(&l);
	ft_printf("%d\n", l.nbants);
	return (0);
}
