/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/


#ifndef MENU_HPP_
#define MENU_HPP_

#include "Game.hpp"
#include <string>
#include "Core.hpp"
#include <dlfcn.h>
#include <irrlicht/irrlicht.h>
#include "Cursor.hpp"
#include "Sounds.hpp"
#include <memory>

using namespace irr;

class Game;

class Menu {
    public:
        Menu(Core *core);
        ~Menu();

        IrrlichtDevice *createWindow(
            int width,
            int length,
            const wchar_t *name
        );
        void createImage(const char *pathImage, int x, int y, IrrlichtDevice *device, video::IVideoDriver *driver);
        gui::IGUIButton *createButton(const wchar_t *text, const char *pathTexture, const char *pathFont, video::IVideoDriver *driver, gui::IGUIEnvironment *gui, int x, int y, int width, int length);

        gui::IGUIEnvironment *createNewGUIEnvironment();

        void InitGuiGame();
        void setName(std::string name);
        std::string getName();
        void setNbPlayer(int nbplayer);
        bool startGame();
        void startOption();
        void DisplayMenu();
    void menuRun(core::vector3d<int> &color);
    void setPage(int);
        int get_page(void);
        void MenuInit();
        void setSound(std::shared_ptr<Sound> sound);
    private:
    std::shared_ptr<Sound> _sound;
        Core *_core;
        int _page;
        std::string _name;
        int _nbplayer;
        gui::IGUIImage *_background;
        gui::IGUIButton *_volume_less;
        gui::IGUIButton *_volume_more;
        gui::IGUIButton *_playButton;
        gui::IGUIButton *_exitButton;
        gui::IGUIEditBox *_nameArea;
};

#endif /* !MENU_HPP_ */
