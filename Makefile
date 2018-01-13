# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:45:14 by lyoung            #+#    #+#              #
#    Updated: 2018/01/08 10:45:15 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spaceinvaders

CFLAG = -Wall -Werror -Wextra

NCURS = -lncurses

HPP = 	space_inv.hpp \
		Game.class.hpp \
		Player.class.hpp \

SRC = 	Game.class.cpp \
		Player.class.cpp \
		main.cpp \

all: $(NAME)

$(NAME): $(HPP) $(SRC)
		@clang++ $(CFLAG) $(NCURS) $(SRC) -o $(NAME)

clean:
		@rm -rf $(NAME)

re: clean all