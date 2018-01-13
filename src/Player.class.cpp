/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:04:14 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 12:04:18 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.class.hpp"

Player::Player(void) : ch('M'), HP(100), pos_y(50), pos_x(50)
{
}

Player::~Player(void)
{
}

char	Player::getCh(void)
{
	return (this->ch);
}

int		Player::getHP(void)
{
	return (this->HP);
}

int		Player::getPosX(void)
{
	return (this->pos_x);
}

int		Player::getPosY(void)
{
	return (this->pos_y);
}

void	Player::setCh(char ch)
{
	this->ch = ch;
}

void	Player::setHP(int nb)
{
	this->HP = nb;
}

void	Player::setPosY(int nb)
{
	this->pos_y = nb;
}

void	Player::setPosX(int nb)
{
	this->pos_x = nb;
}