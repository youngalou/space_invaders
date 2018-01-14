/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:50:09 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 17:37:03 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include "Asset.class.hpp"

class	Bullet : public Asset
{
	public:
		char	spawn;
		
		Bullet(void);
		~Bullet(void);
		Bullet(Bullet const &obj);
		Bullet&	operator=(Bullet const &obj);

		void	check(t_env *env, t_ixy p1_pos);
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

		char	action(t_env *env, Bullet bullet[BULLETS], int input);
};

#endif