# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:54:40 by mlamkadm          #+#    #+#              #
#    Updated: 2025/02/17 18:45:55 by mlamkadm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Scalar.cpp

HEADERS = Scalar.hpp

OBJS = $(SRCS:.cpp=.o)

CC = c++ #-std=c++98

CFLAGS = -Wall -Wextra #-Werror

RM = rm -f

NAME = main

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean

