/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/05 17:43:33 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

#define NBANTS 1
#define ROOM 2
#define LINK 3
#define COMMENT 4
#define START 5
#define END 6
#define COMMAND 7

#define CHECK_   (vist[queue->node] == -1 && queue->flow == c && y == 1 && node[tmp->node] == 0)
#define CHECK_1    (node[vist[tmp->node]] == 1 && lem->adlist[vist[tmp->node]]->node_parent == tmp->node)
#define CHECK_2   ((lem->adlist[vist[tmp->node]]->node_parent != tmp->node && node[vist[tmp->node]] == 0 && node[queue->node] == 1 && lem->adlist[tmp->node]->node_parent == queue->node && tmp->flow == c)

#define CHECK_3  (vist[queue->node] == -1 && queue->flow == c && y == 0 )
#define CHECK_4  (CHECK_3 && (node[tmp->node] == 0 || (node[tmp->node] == 1 &&  CHECK_2 || CHECK_1))))

typedef struct s_print
{
	char *name;
	int scor;
	int bant;
	int len_path;
	struct s_print *next;

} t_print;

typedef struct s_group
{
	char *grp;
	int len_g;
	int scor;
	struct s_group *next;
} t_group;

typedef struct s_queue
{
	int node;
	int flow;
	int node_parent;
	int node_visit;
	int visit;
	struct s_queue *next;
} t_queue;

typedef struct s_bfs
{
	t_queue *q;
	t_queue *last;
	int *vist;
} t_bfs;

typedef struct s_map
{
	char *data;
	int type;
	struct s_map *next;
} t_map;

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_room
{
	t_point cords;
	char *name;
	struct s_room *next;
} t_room;

typedef struct s_lem_in
{
	t_queue **adlist;
	t_group **g;
	char **rooms;
	int *node;
	int nbants;
	int nbrooms;
	int start;
	int end;
	int nbr_ant_start;
	int nbr_ant_end;
	int quit;
	int len;
	int nbr;
	int index;
} t_lem_in;

int get_nbants(t_lem_in *l, char *line);
int read_data(t_map *map, t_lem_in *l);
int check_room(t_room **r, char *line);
int get_rooms(t_lem_in *l, t_room **r, t_map **m, char *line);
int get_links(t_lem_in **l, char *line, char *start, char *end);
int ft_creat_adj(t_lem_in **lst, int nbrooms);
int creat_rooms_array(t_lem_in *l, t_room *room, char **start, char **end);
int contains(t_lem_in *l, char *element, char *start, char *end);
/***********************************************************************/
/////
int *_bfs(t_lem_in *lem, int c, int *node, int y);
void ft_index_path(t_lem_in *lem, int end_room, int strat, int index);
void ft_free_tab(char ***tab);
void ft_free_queue(t_queue **lst);
int ft_index_path_cap(t_lem_in *lem, int end_room, int strat, int index);
void ft_add_group(t_group ***lst, int *group, int end, int i, int j);
void ft_get_best_grp(t_group ***lst, int nbants);
t_lem_in *getset(t_lem_in *l);
void ft_print_instructoin();

void ft_print_adj(t_lem_in *adj);
void ft_ft();
#endif
