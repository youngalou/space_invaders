/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:31:05 by jnederlo          #+#    #+#             */
/*   Updated: 2018/01/14 17:54:17 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.class.hpp"
#include "../includes/space_inv.hpp"

//DEFUALT CONSTRUCTOR:
Enemy::Enemy() : Asset(){
    ch = '#';
    _is_alive = true;
    _move_dir = 0;
}

//DEFUALT CONSTRUCTOR:
// Enemy::Enemy( int y, int x ) : Asset(){

//     ch = '@';
//     pos_y = y;
//     pos_x = x;
    
// }

//DEFAULT DESTRUCTOR:
Enemy::~Enemy( void ){

}

//COPY CONSTRUCTOR OVERLOAD:
Enemy::Enemy( Enemy const &obj ){

    *this = obj;
}

//ASSIGNEMNT OPERATOR OVERLOAD
Enemy &Enemy::operator=( Enemy const &obj ){

    this->ch = obj.ch;
    this->pos_y = obj.pos_y;
    this->pos_x = obj.pos_x;

    return *this;

}

void    Enemy::check(WINDOW *win){
    if (this->_is_alive){
        if (this->_move_dir){ //move left
            if (this->pos_x == 2){
                this->_move_dir = 0;
                this->move(win, this->pos_y + 3, this->pos_x);
            }
            else
                this->move(win, this->pos_y, this->pos_x - 1);
        }
        else if (!this->_move_dir){ //move right
            if (this->pos_x == (WIN_W - 2)){
                this->_move_dir = 1;
                this->move(win, this->pos_y + 3, this->pos_x);
            }
            else
                this->move(win, this->pos_y, this->pos_x + 1);
        }
    }
}

bool    Enemy::status(WINDOW *win)
{
    if (mvwinch(win, this->pos_y, this->pos_x) == 'A')
        return 0;
    if (mvwinch(win, this->pos_y, this->pos_x) == '|')
        this->_is_alive = false;
    else if (this->_is_alive)
    {
        if (this->_move_dir)
        {
            if (mvwinch(win, this->pos_y, this->pos_x - 1) == '|')
            {
                this->_is_alive = false;
                this->move(win, this->pos_y, this->pos_x - 1);
            }
        }
        else if (!this->_move_dir)
        {
            if (mvwinch(win, this->pos_y, this->pos_x + 1) == '|')
            {
                this->_is_alive = false;
                this->move(win, this->pos_y, this->pos_x + 1);
            }
        }
    }
    return 1;
}
