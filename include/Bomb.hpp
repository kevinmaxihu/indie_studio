/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <vector>
#include <iostream>
#include "Character.hpp"

class Bomb
{
    public:
	    Bomb(int pos_x, int pos_y);
		~Bomb();

        void KillSomeone();
        std::vector<std::string> explosion(std::vector<std::string> map);
	protected:
	private:
        int _pos_x;
        int _pos_y;
        int _bombsize;
};

#endif /* !BOMB_HPP_ */
