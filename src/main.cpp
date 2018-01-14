/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:39:17 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 10:45:22 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/space_inv.hpp"
#include "../includes/Asset.class.hpp"
#include "../includes/Player.class.hpp"
#include "../includes/Enemy.class.hpp"

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
	env->p1 = new Player;
	// box(env->win, 0, 0);
	return (env);
}

void	frame(t_env *env)
{
	env->p1->action(env->win, env->bullet, getch());
	for (int i = 0; i < 10; i++)
		env->bullet[i].check(env->win, env->p1->getPosY(), env->p1->getPosX());
}

void	display_enemies(t_env *env){
	int k = 0;
	for (int i = 5; i < (WIN_H - 10); i += 2){
		for(int j = 23; j < (WIN_W - 22); j += 1 ){
			
			if (k >= NUM_ENEMIES)
				return ;
			env->enemy[k].setPosY(i);
			env->enemy[k].setPosX(j);
			env->enemy[k].setChar('@');
			mvwaddch(env->win, env->enemy[k].getPosY(), env->enemy[k].getPosX(), env->enemy[k].getChar());
			k++;
		}
	}
	return ;
}

void	frame(t_env *env, Bullet bullet[BULLETS])
{
	env->p1->action(env->win, bullet, getch());

	for (int i = 0; i < BULLETS; i++)
		bullet[i].check(env->win, env->p1->getPosY(), env->p1->getPosX());
}




void	run_game(t_env *env)
{
	clock_t	now;
	mvwaddstr(env->win, 25, 44, "SPACE INVADERS");
	env->p1->move(env->win, 50, 50);
	display_enemies(env);
	while (1)
	{
		for (int j = 0; j < NUM_ENEMIES; j++)
			env->enemy[j].move( env->win, env->enemy[j].getPosY(), env->enemy[j].getPosX() + 1);
		now = clock();
		while ((clock() / CLOCKS_PER_FRAME) == (now / CLOCKS_PER_FRAME))
		frame(env);
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