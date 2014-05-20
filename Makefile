# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 21:28:36 by ael-kadh          #+#    #+#              #
#    Updated: 2013/12/31 18:53:38 by vjoubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = main.c ft_path.c action.c
HEAD = pipe.h get_next_line.h
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@gcc $(FLAGS) -I libft/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft -o $(NAME)

clean :
	@make -C ./libft clean
	@rm -f $(OBJ)

fclean : clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re