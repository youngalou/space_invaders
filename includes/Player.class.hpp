/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:50:09 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 11:50:10 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include "space_inv.hpp"

class	Player
{
	private:
		char	ch;
		int		HP;
		int		pos_y;
		int		pos_x;
	public:
		char	getCh(void);
		int		getHP(void);
		int		getPosY(void);
		int		getPosX(void);
		
		void	setCh(char ch);
		void	setHP(int nb);
		void	setPosY(int nb);
		void	setPosX(int nb);

		Player(void);
		~Player(void);
};

#endif