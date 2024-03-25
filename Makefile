# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:13:32 by tafocked          #+#    #+#              #
#    Updated: 2024/03/25 21:11:29 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

FILES	= $(wildcard *.c) \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=thread -g
LDLIBS	= -lpthread

FILES_DIR = ./
OBJ_DIR	= .obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:%.c=%.o))

all: $(NAME)

re: fclean all

$(OBJ_DIR)/%.o: $(FILES_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(OPTIONS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
