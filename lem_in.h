/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/14 14:36:15 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_adlist
{
	char			*room;
	struct s_adlist	*next;
}					t_adlist;

typedef struct		s_lem_in
{
	int				nbants;
	char			*comm;
}					t_lem_in;

#endif
