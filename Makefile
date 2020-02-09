# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2020/02/09 05:25:57 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

c_srcs = algo_/ft_bfs.c \
       algo_/ft_fun_free.c\
	   algo_/ft_get_best_g.c \
	   algo_/get_group_.c\
	   algo_/ft_index_path.c \
		read_file/parse_.c\
		main.c \
		read_file/ft_adj_list.c \
		read_file/sort_rooms.c \
		print_/print_instructoin.c \
		print_/ft_get_nbr_path.c \
		ft_mangement.c 

objs = $(c_srcs:.c=.o)
INCLUDES = ./include

FLAGS = -g -Wall -Wextra -Werror

all: libft_ $(NAME)

libft_:
	@make -C libft

$(NAME): $(objs) $(INCLUDES)/lem_in.h libft/libft.a
	gcc -o $(NAME) $(FLAGS) $(objs) -L ./libft -lft -I $(INCLUDES)

$(objs): %.o : %.c 
	gcc  $(FLAGS) -c $< -o $@   -I $(INCLUDES)
clean:
	@make clean -C libft
	@rm -rf $(objs)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all


