# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:13:32 by tafocked          #+#    #+#              #
#    Updated: 2024/03/18 18:16:26 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

FILES	= $(wildcard *.c) \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
LDLIBS	= -lpthread
OBJ = $(FILES:.c=.o) #to define, objs folder or not

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
