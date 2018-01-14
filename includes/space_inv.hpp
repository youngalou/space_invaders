/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_inv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <lyoung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:16:07 by lyoung            #+#    #+#             */
/*   Updated: 2018/01/13 17:54:54 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE_INV_H
#define SPACE_INV_H

#include <curses.h>
#include <ctime>

# define WIN_H 52
# define WIN_W 102
# define BULLETS 10
# define FPS 30
# define CLOCKS_PER_FRAME (CLOCKS_PER_SEC / FPS)

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPACE 32

typedef struct	s_ixy
{
	int			y;
	int			x;
}				t_ixy;

typedef struct	s_env
{
	WINDOW		*win;
}				t_env;

#endif