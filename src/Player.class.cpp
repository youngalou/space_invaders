/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:04:14 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 19:13:35 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.class.hpp"

Player::Player(void) : Asset()
{
	ch = 'M';
	setPosY(50);
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

int			Player::getLives(void)
{
	return (this->lives);
}

int			Player::getAmmo(void)
{
	return (this->ammo);
}

void		Player::setLives(int nb)
{
	this->lives = nb;
}

void		Player::setAmmo(int nb)
{
	this->ammo = nb;
}

void		Player::action(WINDOW *win, Bullet bullet[10], int input)
{
	
	if (input == KEY_UP || input == KEY_W)
		this->move(win, this->pos_y - 1, this->pos_x);
	else if (input == KEY_DOWN || input == KEY_S)
		this->move(win, this->pos_y + 1, this->pos_x);
	else if (input == KEY_LEFT || input == KEY_A)
		this->move(win, this->pos_y, this->pos_x - 1);
	else if (input == KEY_RIGHT || input == KEY_D)
		this->move(win, this->pos_y, this->pos_x + 1);
	else if (input == KEY_SPACE || input == KEY_ENTER)
	{
		for (int i = 0; i < 10; i++)
		{
			if (!bullet[i].spawn)
			{
				bullet[i].spawn = 1;
				return ;
			}
		}
	}
}