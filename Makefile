# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 21:27:32 by akharfat          #+#    #+#              #
#    Updated: 2024/08/03 12:24:14 by akharfat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
HEADER = push_swap.h 

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -rf

SRCF = checks_after.c ft_split.c main_utils.c main.c push.c reverse_rotate.c sort_alg_five.c\
		rotate.c sort_algo.c sort_small.c stack_creation_utils.c stack_creation.c swap.c
OBJF = $(SRCF:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJF)
	$(CC) $(CFLAGS) $(OBJF) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
