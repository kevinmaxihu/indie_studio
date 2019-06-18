/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Assets
*/

#include "Assets.hpp"
#include "FileNotFoundException.hpp"
#include <sys/stat.h>
#include <vector>
#include <string>

Assets::Assets()
{
}

Assets::~Assets()
{
}

void Assets::checkFiles(void) const
{
    struct stat buffer;

    for (std::string name : this->_filesPath) {
        if (stat(name.c_str(), &buffer) < 0)
            throw FileNotFoundException(name);
    }
}

std::string Assets::getFile(FILES file) const
{
    return (this->_filesPath[(int)file]);
}
