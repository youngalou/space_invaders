/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:39:17 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 14:18:16 by lyoung           ###   ########.fr       */
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

t_env	*init_env(void)
{
	t_env	*env;

	env = new t_env;
	env->win = newwin(52, 100, 0, 0);
	box(env->win, 0, 0);
	return (env);
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

void	run_game(t_env *env)
{
	mvwaddstr(env->win, 25, 43, "SPACE INVADERS");
	while (1)
	{
		wrefresh(env->win); //call this every frame to update window
	}
}

int		main(void)
{
	t_env	*env;

	init_curses();
	env = init_env();
	run_game(env);
	endwin(); //call before exiting to restore term settings
	return (0);
}