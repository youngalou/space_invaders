/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asset.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:49:38 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 14:16:14 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Asset.class.hpp"

Asset::Asset(void)
{
}

Asset::~Asset(void)
{
}

Asset::Asset(Asset const &obj)
{
	*this = obj;
}

Asset&		Asset::operator=(Asset const &obj)
{
	this->ch = obj.ch;
	this->pos = obj.pos;
	return (*this);
}

t_ixy		Asset::getPos(void)
{
	return (this->pos);
}

void		Asset::setPos(int y, int x)
{
	this->pos.y = y;
	this->pos.x = x;
}

void		Asset::move(t_env *env, int y, int x)
{
	mvwdelch(env->win, this->pos.y, this->pos.x);
	this->setPos(y, x);
	mvwaddch(env->win, this->pos.y, this->pos.x, this->ch);
}