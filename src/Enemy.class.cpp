/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:31:05 by jnederlo          #+#    #+#             */
/*   Updated: 2018/01/14 12:05:54 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Asset.class.hpp"
#include "../includes/Enemy.class.hpp"
#include "../includes/space_inv.hpp"



//DEFUALT CONSTRUCTOR:
Enemy::Enemy() : Asset(){
    ch = '@';
    _is_alive = true;
    _move_left = false;
    _move_right = true;

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
        if (this->_move_left == true){
            if (this->pos_x == 1){
                this->_move_left = false;
                this->_move_right = true;
                this->move(win, this->pos_y + 3, this->pos_x);
            }
            else
                this->move(win, this->pos_y, this->pos_x - 1);
        }
        else if (this->_move_right == true){
            if (this->pos_x == (WIN_W - 1)){
                this->_move_left = true;
                this->_move_right = false;
                this->move(win, this->pos_y + 3, this->pos_x);
            }
            else
                this->move(win, this->pos_y, this->pos_x + 1);
        }
    }
}
