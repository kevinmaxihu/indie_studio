/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** FileNotFoundException
*/

#include <iostream>
#include "FileNotFoundException.hpp"

FileNotFoundException::FileNotFoundException(const std::string &message)
    : Exception(message)
{
}

FileNotFoundException::~FileNotFoundException()
{
}

const char *FileNotFoundException::what() const throw()
{
    std::string result = "File not found: ";

    result += this->_message;
    std::cout << result << std::endl;
    return (result.c_str());
}