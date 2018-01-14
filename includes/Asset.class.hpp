/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asset.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:43:55 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 12:10:20 by lyoung           ###   ########.fr       */
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

		char	getCh(void);
		int		getPosY(void);
		int		getPosX(void);

		void	setCh(char c);
		void	setPosY(int nb);
		void	setPosX(int nb);

		void	move(WINDOW *win, int y, int x);
};

#endif