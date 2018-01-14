# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:45:14 by lyoung            #+#    #+#              #
#    Updated: 2018/01/13 19:03:13 by jnederlo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spaceinvaders

CFLAG = -Wall -Werror -Wextra

NCURS = -lncurses

HPPFILES =	space_inv.hpp \
			Asset.class.hpp \
			Player.class.hpp \
			Enemy.class.hpp \

SRCFILES =	main.cpp \
			Asset.class.cpp \
			Player.class.cpp \
			Bullet.class.cpp \
			Enemy.class.cpp \

SRC = $(addprefix src/, $(SRCFILES))

HPP = $(addprefix includes/, $(HPPFILES))

all: $(NAME)

$(NAME): $(HPP) $(SRC)
		@clang++ $(CFLAG) $(NCURS) $(SRC) -o $(NAME)

clean:
		@rm -rf $(NAME)

re: clean all