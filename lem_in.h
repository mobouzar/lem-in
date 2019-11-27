/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/27 23:52:08 by mobouzar         ###   ########.fr       */
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


typedef     struct s_queue
{
	int node;
	int flow;
	int cap;
	struct s_queue *next;
}                   t_queue;

typedef		struct s_adjs
{
	int nbroom;
	t_queue		**adjs;
}					t_adjs;

typedef		struct s_bfs
{
	t_queue  		*q;
	t_queue  		*last;
	int     		*vist;
}					t_bfs;



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
	t_point			cords;
	char			*name;
	int				index;
	struct s_room	*next;
}					t_room;

typedef struct		s_adlist
{
	t_room			**room;
	t_room			*head;
	int				capacity;
	int				flow;
	struct s_adlist	*next;
}					t_adlist;

typedef struct		s_lem_in
{
	int				nbants;
	int				nbrooms;
	int				start;
	int				end;
}					t_lem_in;

int		get_nbants(t_lem_in *l, char *line);
int		check_room(t_lem_in *l, t_room **r,t_map *m, char *line);
int		get_rooms(t_lem_in *l, t_room **r, t_map **m, char *line);
int		*_bfs(t_lem_in *lem, t_adjs *adj);
void	ft_index_path(t_adjs *lst,  int end_room, int strat);

#endif
