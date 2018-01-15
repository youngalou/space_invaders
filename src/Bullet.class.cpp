/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:58:01 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 17:48:52 by lyoung           ###   ########.fr       */
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
		if (mvwinch(win, this->pos_y - 1, this->pos_x) == '#' || this->pos_y < 1)
			this->spawn = 0;
		this->move(win, this->pos_y - 1, this->pos_x);
	}
	else
	{
		this->setPosY(p1_y);
		this->setPosX(p1_x);
	}
}

void		Bullet::destroy(WINDOW *win)
{
	if (mvwinch(win, this->pos_y, this->pos_x) == '#' || this->pos_y < 1)
	{
		this->spawn = 0;
		mvwaddch(win, this->pos_y, this->pos_x, ' ');
	}
	else if (!this->spawn)
	{
		if (mvwinch(win, this->pos_y, this->pos_x) == '|')
			mvwaddch(win, this->pos_y, this->pos_x, ' ');
	}
}