/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:58:01 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 17:36:04 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.class.hpp"

Bullet::Bullet(void) : Asset()
{
	ch = '|';
	setPos(0, 0);
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
	this->pos = obj.pos;
	this->spawn = obj.spawn;
	return (*this);
}

void		Bullet::check(t_env *env, t_ixy p1_pos)
{
	if (this->spawn)
	{
		this->move(env, this->pos.y - 1, this->pos.x);
		if (this->pos.y <= 0)
		{
			this->spawn = 0;
			this->setPos(p1_pos.y, p1_pos.x);
		}
	}
	else
		this->setPos(p1_pos.y, p1_pos.x);
}