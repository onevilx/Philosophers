# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 19:09:46 by yaboukir          #+#    #+#              #
#    Updated: 2025/03/02 16:48:38 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PHILO = philo/main.c philo/ft_waiter.c philo/ft_actions.c \
			 philo/ft_declare.c philo/ft_pthreads.c philo/ft_helpers.c \

#SRCS_PHILO_BONUS =

OBJS_PHILO = $(SRCS_PHILO:.c=.o)
#OBJS_PHILO_BONUS = $(SRCS_PHILO_BONUS:.c=.o)

CC = cc
AR = ar r
RM = rm -f
CFLAGS = #-Wall -Wextra -Werror
INCLUDE = philo/philo.h
INCLUDE_BONUS = philo_bonus/philo_bonus.h
NAME_PHILO = philo_exe
#NAME_PHILO_BONUS =

all: $(NAME_PHILO)

$(NAME_PHILO): $(OBJS_PHILO)
	$(CC) $(CFLAGS) $(OBJS_PHILO) -o $(NAME_PHILO)

#bonus: $(NAME_PHILO_BONUS)

#$(NAME_PHILO_BONUS): $(OBJS_PHILO_BONUS)
#	$(CC) $(CFLAGS) $(OBJS_PHILO_BONUS) -o $(NAME_PHILO_BONUS)

philo/%.o: philo/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#bonus/%.o: bonus/%.c $(INCLUDE_BONUS)
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_PHILO) $(OBJS_PHILO_BONUS)

fclean: clean
	$(RM) $(NAME_PHILO) $(NAME_PHILO_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
