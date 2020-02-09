# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2020/02/09 12:24:33 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

objs = algo_/ft_bfs.o \
       algo_/ft_fun_free.o\
	   algo_/ft_get_best_g.o \
	   algo_/get_group_.o\
	   algo_/ft_index_path.o \
	   algo_/ft_free.o\
		read_file/parse_.o\
		main.o \
		read_file/ft_adj_list.o \
		read_file/sort_rooms.o \
		print_/print_instructoin.o \
		print_/ft_get_nbr_path.o \
		ft_mangement.o 

 
INCLUDES = ./include

CFLAGS = -g -Wall -Wextra -Werror

cc = gcc

all: libft_ $(NAME)

libft_:
	@make -C libft

$(NAME): libft_ $(objs) $(INCLUDES)/lem_in.h libft/libft.a
	$(cc) -o $(NAME) $(CFLAGS) $(objs) -L ./libft -lft -I $(INCLUDES)

clean:
	@make clean -C libft
	@rm -rf $(objs)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all


