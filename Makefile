# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:13:32 by tafocked          #+#    #+#              #
#    Updated: 2024/03/03 18:41:58 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

FILES	= philosophers.c \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
LDLIBS	=

OBJS = $(addprefix $(OBJS_DIR)/, $(FILES:%.c=%.o)) #to define, objs folder or not

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
