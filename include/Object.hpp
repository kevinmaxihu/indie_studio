/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <vector>

class Object {
    public:
        Object();
        ~Object();

        std::vector<int> spawnObject();
    private:
        int _typeObject;
        std::vector<int> _position;
};

#endif /* !OBJECT_HPP_ */
