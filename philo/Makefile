# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 19:09:46 by yaboukir          #+#    #+#              #
#    Updated: 2025/03/03 04:08:07 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PHILO = philo.c ft_waiter.c ft_actions.c ft_declare.c ft_pthreads.c ft_helpers.c \

OBJS_PHILO = $(SRCS_PHILO:.c=.o)

CC = cc
AR = ar r
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = philo.h
NAME_PHILO = philo

all: $(NAME_PHILO)

$(NAME_PHILO): $(OBJS_PHILO)
	$(CC) $(CFLAGS) $(OBJS_PHILO) -o $(NAME_PHILO)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_PHILO)

fclean: clean
	$(RM) $(NAME_PHILO)

re: fclean all

.PHONY: clean fclean re all
