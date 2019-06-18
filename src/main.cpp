/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include "FileNotFoundException.hpp"
#include "Game.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac > 1) {
        std::cout << av[1] << " is not necessary" << std::endl <<"USAGE: ./bomberman port" << std::endl;
        return (84);
    } else {
        try {
            Game game;
            game.begin();
        } catch (FileNotFoundException &fnf) {
            fnf.what();
            return (84);
        } catch (Exception &e) {
            std::cerr << e.what() << std::endl;
            return (84);
        }
    }
    return (0);
}
