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

#include <curses.h>
#include <iostream>

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
}