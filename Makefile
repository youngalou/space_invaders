# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:45:14 by lyoung            #+#    #+#              #
#    Updated: 2018/01/13 14:10:55 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spaceinvaders

CFLAG = -Wall -Werror -Wextra

NCURS = -lncurses

HPPFILES =	space_inv.hpp \
			Asset.class.hpp \

SRCFILES =	main.cpp \
			Asset.class.cpp \

SRC = $(addprefix src/, $(SRCFILES))

HPP = $(addprefix includes/, $(HPPFILES))

all: $(NAME)

$(NAME): $(HPP) $(SRC)
		@clang++ $(CFLAG) $(NCURS) $(SRC) -o $(NAME)

clean:
		@rm -rf $(NAME)

re: clean all