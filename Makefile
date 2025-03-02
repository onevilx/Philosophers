# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 19:09:46 by yaboukir          #+#    #+#              #
#    Updated: 2025/03/01 19:21:26 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PHILO = mandatory/main.c mandatory/ft_waiter.c mandatory/ft_actions.c \
			 mandatory/ft_declare.c mandatory/ft_pthreads.c mandatory/ft_helpers.c \

#SRCS_PHILO_BONUS =

OBJS_PHILO = $(SRCS_PHILO:.c=.o)
#OBJS_PHILO_BONUS = $(SRCS_PHILO_BONUS:.c=.o)

CC = cc
AR = ar r
RM = rm -f
CFLAGS = #-Wall -Wextra -Werror
INCLUDE = mandatory/philo.h
INCLUDE_BONUS = bonus/philo_bonus.h
NAME_PHILO = philo
#NAME_PHILO_BONUS = checker

all: $(NAME_PHILO)

$(NAME_PHILO): $(OBJS_PHILO)
	$(CC) $(CFLAGS) $(OBJS_PHILO) -o $(NAME_PHILO)

#bonus: $(NAME_PHILO_BONUS)

#$(NAME_PHILO_BONUS): $(OBJS_PHILO_BONUS)
#	$(CC) $(CFLAGS) $(OBJS_PHILO_BONUS) -o $(NAME_PHILO_BONUS)

mandatory/%.o: mandatory/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#bonus/%.o: bonus/%.c $(INCLUDE_BONUS)
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_PHILO) $(OBJS_PHILO_BONUS)

fclean: clean
	$(RM) $(NAME_PHILO) $(NAME_PHILO_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
