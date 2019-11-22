/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/22 23:58:32 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <fcntl.h>

# define NBANTS 1
# define ROOM 2
# define LINK 3
# define COMMENT 4
# define START 5
# define END 6
# define COMMAND 7

typedef struct		s_map 
{
	char			*data;
	int				type;
	struct s_map	*next;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	char			*room;
	t_point			cords;
}					t_room;

typedef struct		s_lem_in
{
	t_room			*rooms;
	int				nbants;
	int				nbrooms;
}					t_lem_in;

int		get_nbants(t_lem_in *l, char *line);
int		check_room(t_lem_in *l, t_map *m, char *line);
int		get_rooms(t_lem_in *l, t_map **m, char *line, char *cmd);

#endif
