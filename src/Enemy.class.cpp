/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:31:05 by jnederlo          #+#    #+#             */
/*   Updated: 2018/01/13 19:08:50 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Asset.class.hpp"
#include "../includes/Enemy.class.hpp"


//DEFUALT CONSTRUCTOR:
Enemy::Enemy( void ) : Asset(){
    
}

//DEFUALT CONSTRUCTOR:
Enemy::Enemy( int y, int x ) : Asset(){

    ch = '@';
    pos_y = y;
    pos_x = x;
    
}

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
