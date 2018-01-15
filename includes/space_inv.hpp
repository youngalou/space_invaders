/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_inv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:16:07 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/14 17:47:11 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE_INV_H
#define SPACE_INV_H

#include "Player.class.hpp"
#include "Enemy.class.hpp"
#include <curses.h>
#include <ctime>
#include <iostream>

# define WIN_H 52
# define WIN_W 102
# define BULLETS 10
# define NUM_ENEMIES 200
# define FPS 30
# define CLOCKS_PER_FRAME (CLOCKS_PER_SEC / FPS)
# define WAIT (CLOCKS_PER_SEC * 2)

typedef struct	s_env
{
	WINDOW		*win;
	Player		*p1;
	Bullet		bullet[10];
	Enemy 		enemy[NUM_ENEMIES];
	size_t		frame_count;
	int			speed;
	int			stars[50];
}				t_env;

#endif