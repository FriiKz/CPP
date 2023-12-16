# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 16:08:55 by lbusi             #+#    #+#              #
#    Updated: 2023/12/15 22:54:28 by lbusi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRCS = main.cpp RPN.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re