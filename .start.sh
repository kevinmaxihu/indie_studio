#!/bin/zsh

if [ "$1" = "re" ]
then
    cmake .
    make clean
    make
elif [ "$1" = "clean" ]
then
    cmake .
    make clean
elif [ "$1" = "fclean" ]
then
    cmake .
    make clean
else
    cmake .
    make
fi
