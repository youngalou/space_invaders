/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:39:17 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 17:59:45 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/space_inv.hpp"
#include "../includes/Asset.class.hpp"
#include "../includes/Player.class.hpp"

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
	t_env *env = new t_env;

	env->win = newwin(WIN_H, WIN_W, 0, 0);
	// box(env->win, 0, 0);
	return (env);
}

void	frame(t_env *env, Player *p1, Bullet bullet[BULLETS])
{
	p1->action(env, bullet, getch());
	for (int i = 0; i < BULLETS; i++)
		bullet[i].check(env, p1->getPos());
}

void	run_game(t_env *env)
{
	clock_t	now;
	Player	*p1 = new Player;
	Bullet 	bullet[10];
	mvwaddstr(env->win, 25, 44, "SPACE INVADERS");
	p1->move(env, 50, 50);
	while (1)
	{
		now = clock();
		while ((clock() / CLOCKS_PER_FRAME) == (now / CLOCKS_PER_FRAME))
		frame(env, p1, bullet);
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