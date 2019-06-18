/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#include "Menu.hpp"
#include "Assets.hpp"
#include <unistd.h>

Menu::Menu(Core *core)
{
    // this->_game = game;
    this->_core = core;
}

Menu::~Menu()
{
}

void Menu::MenuInit()
{
    this->_core->addImage(Assets::FILES::BACKGROUND, 0, 0);
    _volume_more = this->_core->addButton(
        L"Sound +", Assets::FILES::BUTTON_A, Assets::FILES::FONT_CLASSIC,
        871, 605, 1059, 655
        );
     _volume_less = this->_core->addButton(
        L"Sound -", Assets::FILES::BUTTON_A, Assets::FILES::FONT_CLASSIC,
        871, 695, 1059, 745
        );
    _playButton = this->_core->addButton(
        L"Play", Assets::FILES::BUTTON_A, Assets::FILES::FONT_CLASSIC,
        871, 515, 1059, 565
        );
    _exitButton = this->_core->addButton(
        L"Exit", Assets::FILES::BUTTON_A, Assets::FILES::FONT_CLASSIC,
        871, 785, 1059, 835
        );
    _nameArea = this->_core->addTextArea(
        L"Enter Name", Assets::FILES::FONT_CLASSIC,
        871, 425, 1059, 475
        );
    _page = 100;
}

void Menu::setSound(std::shared_ptr<Sound> sound)
{
    _sound = sound;
}

void Menu::menuRun(core::vector3d<int> &color)
{
    if (_page == 100) {
        if (this->_exitButton->isPressed()) {            
            _sound->play(Sound::PLAYLIST::CLICK_S, false);
            _sound->play(Sound::PLAYLIST::EXIT2_S, false);
            sleep(1);
            this->_page = 99;
        }
        if (this->_playButton->isPressed()) {            
            _sound->play(Sound::PLAYLIST::CLICK_S, false);
            const wchar_t *text = _nameArea->getText();
            std::wstring ws(text);
            std::string name(ws.begin(), ws.end());
            this->setName(name);
            srand((unsigned)time(0));
            color.X = (rand() % 255);
            color.Y = (rand() % 255);
            color.Z = (rand() % 255);
            this->_page = 200;
        }
        if (this->_volume_less->isPressed()) {
            _sound->play(Sound::PLAYLIST::CLICK_S, false);
            _sound->volume(_sound->getVolume() - 0.25);
        }
        if (this->_volume_more->isPressed()) {
            _sound->play(Sound::PLAYLIST::CLICK_S, false);
            _sound->volume(_sound->getVolume() + 0.25);
        }
    }
}

void Menu::setPage(int page)
{
    _page = page;
}

int Menu::get_page(void)
{
    return (this->_page);
}

void Menu::setName(std::string name)
{
    this->_name = name;
}

std::string Menu::getName()
{
    return(this->_name);
}

void Menu::setNbPlayer(int nbplayer)
{
    this->_nbplayer = nbplayer;
}

bool Menu::startGame()
{
    const wchar_t *wstr = this->_core->ConvertStrToW(getName());
    this->_core->addImage(Assets::FILES::OVERLAY, 0, 0);
    this->_core->addText(wstr, Assets::FILES::FONT_CLASSIC, 100, 100, 300, 200);
}

void Menu::startOption()
{

}
