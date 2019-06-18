/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Cursor
*/

#include "Cursor.hpp"
//#include "Menu.hpp"
//#include "Core.hpp"

Cursor::Cursor(IrrlichtDevice *pDevice, const io::path &filename)
{
    device = pDevice;
    driver = device->getVideoDriver();
    cursorTex = driver->getTexture(filename);
    device->getCursorControl()->setVisible(false);
    picSizeX = cursorTex->getSize().Width;
    picSizeY = cursorTex->getSize().Height;
}

Cursor::~Cursor()
{
}

void Cursor::drawCursor()
{
    driver->draw2DImage(cursorTex,
        device->getCursorControl()->getPosition(),
        core::recti(0, 0, picSizeX, picSizeY), 0,
        video::SColor(255, 255, 255, 255), true);
}
