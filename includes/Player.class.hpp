/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:50:09 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 19:13:24 by lyoung           ###   ########.fr       */
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

class	Bullet : public Asset
{
	public:
		char	spawn;
		
		Bullet(void);
		~Bullet(void);
		Bullet(Bullet const &obj);
		Bullet&	operator=(Bullet const &obj);

		void	check(WINDOW *win, int p1_y, int p1_x);
};

class	Player : public Asset
{
	private:
		int		lives;
		int		ammo;
	
	public:
		Player(void);
		~Player(void);
		Player(Player const &obj);
		Player&	operator=(Player const &obj);

		int		getLives(void);
		int		getAmmo(void);

		void	setLives(int nb);
		void	setAmmo(int nb);

		void	action(WINDOW *win, Bullet bullet[10], int input);
};

#endif