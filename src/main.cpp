/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:39:17 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 17:09:06 by jnederlo         ###   ########.fr       */
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
	start_color();
	srand(time(NULL));
}

t_env	*init_env(void)
{
	t_env *env = new t_env;

	env->win = newwin(WIN_H, WIN_W, 0, 0);
	env->p1 = new Player;
	env->frame_count = 0;
	env->speed = 4;
	env->score = 0;
	box(env->win, 0, 0);
	return (env);
}

void	frame(t_env *env)
{
	env->p1->action(env->win, env->bullet, getch());
	for (int i = 0; i < 10; i++)
		env->bullet[i].check(env->win, env->p1->getPosY() - 1, env->p1->getPosX());
	env->frame_count++;
	if (env->frame_count % 100 == 0)
		env->speed = (rand() % 4) + 1;
	for (int j = 0; j < NUM_ENEMIES; j++)
	{
		env->enemy[j].status(env->win);
		if (env->frame_count % env->speed == 0)
			env->enemy[j].check(env->win);
	}
	for (int i = 0; i < 10; i++)
		env->score += env->bullet[i].destroy(env->win);
}

void	init_enemies(t_env *env){
	int i = 0;
	for(int col = 11; col < (WIN_W - 11); col += 2 ){
		for (int row = 5; row < 15; row += 2){
			if (i >= NUM_ENEMIES)
				return ;
			env->enemy[i].setPosY(row);
			env->enemy[i].setPosX(col);
			mvwaddch(env->win, env->enemy[i].getPosY(), env->enemy[i].getPosX(), env->enemy[i].getCh());
			i++;
		}
	}
	return ;
}

void	game_start(t_env *env)
{
	mvwaddstr(env->win, 25, 44, "SPACE INVADERS");
	clock_t now = clock();
	while ((clock() / WAIT) == (now / WAIT))
		wrefresh(env->win);
	mvwaddstr(env->win, 25, 44, "              ");
	box(env->win, 0, 0);
	env->p1->move(env->win, 49, 50);
	init_enemies(env);
}

bool	run_game(t_env *env)
{
	game_start(env);
	while (1)
	{
		frame(env);
		clock_t now = clock();
		while ((clock() / CLOCKS_PER_FRAME) == (now / CLOCKS_PER_FRAME))
		wrefresh(env->win); //call this every frame to update window
		if (env->score >= NUM_ENEMIES)
		{
			mvwaddstr(env->win, 25, 44, "YOU WIN!");
			return(1);
		}
	}
	return(0);
}

int		main(void)
{
	t_env	*env;
	int		win;

	init_curses();
	env = init_env();
	win = run_game(env);
	if (win)
		mvwaddstr(env->win, 25, 44, "YOU WIN!");
	
	endwin(); //call before exiting to restore term settings
	return (0);
}