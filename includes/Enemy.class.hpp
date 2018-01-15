/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:22:03 by jnederlo          #+#    #+#             */
/*   Updated: 2018/01/14 17:54:18 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "Asset.class.hpp"
#include <curses.h>

class Enemy: public Asset{

public:
    Enemy( void );
    Enemy( int x, int y );
    ~Enemy( void );
    Enemy( Enemy const & obj );
    Enemy & operator=( Enemy const & obj );

    void    check(WINDOW *win);
    bool    status(WINDOW *win);

private:
    bool _is_alive;
    bool _move_dir;
};


#endif