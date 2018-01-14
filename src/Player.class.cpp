/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:04:14 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 17:37:05 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.class.hpp"

Player::Player(void) : Asset()
{
	ch = 'M';
	setPos(50, 50);
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
	this->pos = obj.pos;
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

char		Player::action(t_env *env, Bullet bullet[BULLETS], int input)
{
	
	if (input == KEY_UP || input == KEY_W)
		this->move(env, this->pos.y - 1, this->pos.x);
	else if (input == KEY_DOWN || input == KEY_S)
		this->move(env, this->pos.y + 1, this->pos.x);
	else if (input == KEY_LEFT || input == KEY_A)
		this->move(env, this->pos.y, this->pos.x - 1);
	else if (input == KEY_RIGHT || input == KEY_D)
		this->move(env, this->pos.y, this->pos.x + 1);
	else if (input == KEY_SPACE || input == KEY_ENTER)
	{
		for (int i = 0; i < BULLETS; i++)
		{
			if (!bullet[i].spawn)
				bullet[i].spawn = 1;
		}
	}
	return (0);
}