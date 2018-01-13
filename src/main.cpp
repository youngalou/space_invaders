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

#include "../includes/space_inv.hpp"

void	init_curses(void)
{
	initscr();
	cbreak();
	noecho(); //suppress echoed typed chars
	keypad(stdscr, TRUE); //capture special keys
	nodelay(stdscr, TRUE); //getch will return ERR if key is not ready
	curs_set(0);
}

// void	process_input(void)
// {
// 	int		input;

// 	input = getch();
// 	if (input == KEY_LEFT)
// 	{
// 		mvwdelch(win, p1.getPosY(), p1.getPosX());
// 		p1.setPosX(p1.getPosX() - 1);
// 		mvwaddch(win, p1.getPosY(), p1.getPosX(), p1.getCh());
// 	}
// 	else if (input == KEY_RIGHT)
// 	{
// 		mvwdelch(win, p1.getPosY(), p1.getPosX());
// 		p1.setPosX(p1.getPosX() + 1);
// 		mvwaddch(win, p1.getPosY(), p1.getPosX(), p1.getCh());
// 	}
// }

int		main(void)
{
	init_curses();
	WINDOW	*win = newwin(52, 100, 0, 0);
	box(win, 0, 0);
	mvwaddstr(win, 25, 43, "SPACE INVADERS");
	Player	p1;
	mvwaddch(win, p1.getPosY(), p1.getPosX(), p1.getCh());
	while (1)
	{
		// process_input();
		wrefresh(win); //call this every frame to update window
	}
	endwin(); //call before exiting to restore term settings
}