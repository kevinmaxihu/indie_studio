/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Exception
*/

#include "Exception.hpp"

Exception::Exception(const std::string &message)
    : std::exception(), _message(message)
{
    this->_message = message;
}

Exception::~Exception()
{
}

const char *Exception::what() const throw()
{
    return (this->_message.c_str());
}