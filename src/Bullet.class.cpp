/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:58:01 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 19:31:26 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.class.hpp"

Bullet::Bullet(void) : Asset()
{
	ch = '|';
	this->setPosY(0);
	this->setPosX(0);
	spawn = 0;
}

Bullet::~Bullet(void)
{
}

Bullet::Bullet(Bullet const &obj)
{
	*this = obj;
}

Bullet&		Bullet::operator=(Bullet const &obj)
{
	this->ch = obj.ch;
	this->pos_y = obj.pos_y;
	this->pos_x = obj.pos_x;
	this->spawn = obj.spawn;
	return (*this);
}

void		Bullet::check(WINDOW *win, int p1_y, int p1_x)
{
	if (this->spawn)
	{
		this->move(win, this->pos_y - 1, this->pos_x);
		if (this->pos_y < 0)
		{
			this->spawn = 0;
			this->setPosY(p1_y);
			this->setPosX(p1_x);
		}
	}
	else
	{
		this->setPosY(p1_y);
		this->setPosX(p1_x);
	}
}