/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asset.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:43:55 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 14:16:12 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include "space_inv.hpp"

class	Asset
{
	protected:
		char	ch;
		t_ixy	pos;

	public:
		Asset(void);
		~Asset(void);
		Asset(Asset const &obj);

		Asset&	operator=(Asset const &obj);
		t_ixy	getPos(void);
		void	setPos(int y, int x);

		void	move(t_env *env, int y, int x);
};

#endif