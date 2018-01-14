/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_inv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:16:07 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 18:42:13 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE_INV_H
#define SPACE_INV_H

#include "Player.class.hpp"
#include <curses.h>
#include <ctime>

# define WIN_H 52
# define WIN_W 102
# define BULLETS 10
# define FPS 30
# define CLOCKS_PER_FRAME (CLOCKS_PER_SEC / FPS)

typedef struct	s_env
{
	WINDOW		*win;
	Player		*p1;
	// Bullet		bullet[BULLETS];
}				t_env;

#endif