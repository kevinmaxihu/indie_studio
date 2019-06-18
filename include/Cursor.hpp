/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Cursor
*/


#ifndef CURSOR_HPP_
#define CURSOR_HPP_

#include <string>
#include <iostream>
#include <dlfcn.h>
#include <irrlicht/irrlicht.h>
#include "Assets.hpp"

using namespace irr;

class Cursor {
    public:
        Cursor();
        Cursor(IrrlichtDevice *pDevice, const io::path &filename);
        ~Cursor();

        void drawCursor();
    protected:
    private:
        IrrlichtDevice      *device;
        video::IVideoDriver *driver;
        video::ITexture     *cursorTex;
        u32 picSizeX;
        u32 picSizeY;
};

#endif /* !CURSOR_HPP_ */
