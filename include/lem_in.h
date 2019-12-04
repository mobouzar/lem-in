/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/12/04 19:26:33 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
#include <stdio.h>

# define NBANTS 1
# define ROOM 2
# define LINK 3
# define COMMENT 4
# define START 5
# define END 6
# define COMMAND 7



typedef		struct 		s_group
{
	char				*grp;
	int					len_g;
	struct s_group		*next;
}						t_group;

typedef     struct	s_queue
{
	int				node;
	int				flow;
	struct s_queue	*next;
}                   t_queue;


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
	struct s_room	*next;
}					t_room;

typedef struct		s_lem_in
{
	t_queue			**adlist;
	char			**rooms;
	int				nbants;
	int				nbrooms;
	int				start;
	int				end;
}					t_lem_in;

int		get_nbants(t_lem_in *l, char *line);
int		read_data(t_map *map, t_lem_in *l);
int		check_room(t_room **r, char *line);
int		get_rooms(t_lem_in *l, t_room **r, t_map **m, char *line);
int		get_links(t_lem_in **l, char *line);
int		ft_creat_adj(t_lem_in **lst, int nbrooms);
int		creat_rooms_array(t_lem_in *l, t_room *room);
int		contains(t_lem_in *l, char *element);

// int		*_bfs(t_lem_in *lem, t_adjs *adj);
// void	ft_index_path(t_adjs *lst,  int end_room, int strat);

int						*_bfs(t_lem_in *lem, int c);
void					ft_index_path( t_lem_in *lem, int end_room, int strat);
void    				ft_free_tab(char ***tab);
void					ft_free_queue(t_queue **lst);
int						ft_index_path_cap(t_lem_in *lem,   int end_room, int strat);
void    				ft_add_group(t_group ***lst, int *group, int end, int i);
void    				ft_get_best_grp(t_group ***lst, int nbants);
#endif