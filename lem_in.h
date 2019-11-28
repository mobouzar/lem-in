/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/28 22:10:14 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <fcntl.h>
#include <stdio.h>

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
	struct s_queue *next;
}                   t_queue;

typedef		struct s_path
{
	char			*grp;
	int				len_g;
	struct s_path 	*next;
}					t_path;

typedef		struct s_group
{
	struct s_group 	*next;
	struct s_path 	*avnc;
}					t_group;
	

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
	char			*room;
	t_point			cords;
}					t_room;

typedef struct		s_lem_in
{
	t_room			**rooms;
	int				nbants;
	int				nbrooms;
	int				start;
	int				end;
}					t_lem_in;

int		get_nbants(t_lem_in *l, char *line);
int		check_room(t_lem_in *l, t_map *m, char *line);
int		get_rooms(t_lem_in *l, t_map **m, char *line, char *cmd);
int		*_bfs(t_lem_in *lem, t_adjs *adj, int c);
void	ft_index_path(t_adjs *lst,  int end_room, int strat);
void    ft_free_tab(char ***tab);
void	ft_free_queue(t_queue **lst);
int		ft_index_path_cap(t_adjs *lst,  int end_room, int strat);



#endif
