# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:13:32 by tafocked          #+#    #+#              #
#    Updated: 2024/03/13 17:36:05 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

FILES	= philosophers.c \
			ft_argcheck.c \
			ft_atoi.c \
			ft_init.c \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
LDLIBS	=
OBJ = $(FILES:%.c=%.o) #to define, objs folder or not

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
