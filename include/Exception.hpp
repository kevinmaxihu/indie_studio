/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : public std::exception {
    public:
        Exception(const std::string &message);
        ~Exception();

        virtual const char* what() const throw();
    protected:
        std::string _message;
};

#endif /* !EXCEPTION_HPP_ */
