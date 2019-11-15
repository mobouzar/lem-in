/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/15 15:31:40 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_point
{
	int				y;
	int				x;
}					t_point;

typedef struct		s_map 
{
	char			*map;
	struct s_map	*next;
}					t_map;

typedef struct		s_room
{
	char			*room;
	t_point			cords;
}					t_room;

typedef struct		s_lem_in
{
	t_room			*room;
	char			*comment;
	int				nbants;
}					t_lem_in;

int		get_nbrofants(t_lem_in *l, char *line);

#endif
