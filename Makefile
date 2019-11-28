# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2019/11/28 20:58:51 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

c_srcs =_bfs.c \
       ft_fun_free.c\
	   list_adjs_.c	

objs = $(c_srcs:.c=.o)
INCLUDES = .

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


