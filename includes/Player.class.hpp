/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:50:09 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 17:47:48 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include "Asset.class.hpp"
#include <curses.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPACE 32
# define KEY_ESC 27

class	Bullet : public Asset
{
	public:
		bool		spawn;
		static int	score;
		
		Bullet(void);
		~Bullet(void);
		Bullet(Bullet const &obj);
		Bullet&	operator=(Bullet const &obj);

		void	check(WINDOW *win, int p1_y, int p1_x);
		void	destroy(WINDOW *win);
};

class	Player : public Asset
{
	public:
		Player(void);
		~Player(void);
		Player(Player const &obj);
		Player&	operator=(Player const &obj);

		bool	action(WINDOW *win, Bullet bullet[10], int input);
};

#endif