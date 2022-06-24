# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 03:36:24 by mabdelba          #+#    #+#              #
#    Updated: 2022/06/17 12:08:26 by mabdelba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c ft_parsing.c ft_isdigit.c ft_atoi_l.c ft_atoi.c collect_data.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
# FLAGS = -Wall -Wextra -Werror

NAME = philo


%.o : %.c philosophers.h
	$(CC) $(FLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJS)	
	$(CC) $(FLAGS)  $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_BNS)

fclean : clean
	rm -f $(NAME) $(NAME_2)

re : fclean all 