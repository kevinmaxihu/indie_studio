/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** FileNotFoundException
*/

#ifndef FILENOTFOUNDEXCEPTION_HPP_
#define FILENOTFOUNDEXCEPTION_HPP_

#include <string>
#include "Exception.hpp"

class FileNotFoundException : public Exception {
    public:
        FileNotFoundException(const std::string &message);
        ~FileNotFoundException();

        const char *what() const throw() override;
};

#endif /* !FILENOTFOUNDEXCEPTION_HPP_ */
