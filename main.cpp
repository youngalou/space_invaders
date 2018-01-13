/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:39:17 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 10:39:21 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space_inv.hpp"

void	init_curses(void)
{
	initscr();
	cbreak();
	noecho(); //suppress echoed typed chars
	keypad(stdscr, TRUE); //capture special keys
}

int		main(void)
{
	init_curses();
	WINDOW	*win = newwin(50, 100, 0, 0);
	box(win, 0, 0);
	mvwaddstr(win, 25, 43, "SPACE INVADERS");
	while (1)
	{
		wrefresh(win); //call this every frame to update window
	}
	endwin(); //call before exiting to restore term settings
}