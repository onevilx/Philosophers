# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 19:09:46 by yaboukir          #+#    #+#              #
#    Updated: 2025/03/03 04:04:23 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PHILO_BONUS = philo_bonus.c ft_waiter_bonus.c ft_actions_bonus.c ft_declare_bonus.c \
					ft_pthreads_bonus.c ft_helpers_bonus.c \

OBJS_PHILO_BONUS = $(SRCS_PHILO_BONUS:.c=.o)

CC = cc
AR = ar r
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = philo_bonus.h
NAME_PHILO_BONUS = philo_bonus

bonus: $(NAME_PHILO_BONUS)

$(NAME_PHILO_BONUS): $(OBJS_PHILO_BONUS)
	$(CC) $(CFLAGS) $(OBJS_PHILO_BONUS) -o $(NAME_PHILO_BONUS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_PHILO_BONUS)

fclean: clean
	$(RM) $(NAME_PHILO_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
