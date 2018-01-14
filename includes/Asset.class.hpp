/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asset.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:43:55 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 10:51:29 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_H
#define ASSET_H

#include <curses.h>

class	Asset
{
	protected:
		char	ch;
		int		pos_y;
		int		pos_x;

	public:
		Asset(void);
		~Asset(void);
		Asset(Asset const &obj);
		Asset&	operator=(Asset const &obj);

		// char	getCh(void);
		int		getPosY(void);
		int		getPosX(void);

		// void	setCh(char ch);
		void	setPosY(int nb);
		void	setPosX(int nb);
		void	setCh(char c);
		char	getCh(void);

		void	move(WINDOW *win, int y, int x);
};

#endif