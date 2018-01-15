/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:04:14 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 17:58:47 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.class.hpp"

Player::Player(void) : Asset()
{
	ch = 'A';
	setPosY(49);
	setPosX(50);
}

Player::~Player(void)
{
}

Player::Player(Player const &obj)
{
	*this = obj;
}

Player&		Player::operator=(Player const &obj)
{
	this->ch = obj.ch;
	this->pos_y = obj.pos_y;
	this->pos_x = obj.pos_x;
	return (*this);
}

bool		Player::action(WINDOW *win, Bullet bullet[10], int input)
{
	if (input == KEY_UP && this->pos_y > 1)
		this->move(win, this->pos_y - 1, this->pos_x);
	else if (input == KEY_DOWN && this->pos_y < 50)
		this->move(win, this->pos_y + 1, this->pos_x);
	else if (input == KEY_LEFT && this->pos_x > 1)
		this->move(win, this->pos_y, this->pos_x - 1);
	else if (input == KEY_RIGHT && this->pos_x < 100)
		this->move(win, this->pos_y, this->pos_x + 1);
	else if (input == KEY_SPACE)
	{
		for (int i = 0; i < 10; i++)
		{
			if (!bullet[i].spawn)
			{
				bullet[i].spawn = 1;
				return (1);
			}
		}
	}
	else if (input == KEY_HOME)
		return (0);
	return (1);
}