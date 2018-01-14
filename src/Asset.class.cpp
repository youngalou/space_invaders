/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asset.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:49:38 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 18:45:25 by lyoung           ###   ########.fr       */
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
	this->pos_y = obj.pos_y;
	this->pos_x = obj.pos_x;
	return (*this);
}

int			Asset::getPosY(void)
{
    return (this->pos_y);
}

int			Asset::getPosX(void)
{
    return (this->pos_x);
}

void        Asset::setPosY(int nb)
{
    this->pos_y = nb;
}

void        Asset::setPosX(int nb)
{
    this->pos_x = nb;
}

void		Asset::move(WINDOW *win, int y, int x)
{
	mvwdelch(win, this->pos_y, this->pos_x);
	this->setPosY(y);
	this->setPosX(x);
	mvwaddch(win, this->pos_y, this->pos_x, this->ch);
}