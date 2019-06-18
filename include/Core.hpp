/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <irrlicht/irrlicht.h>
#include <string>
#include "Assets.hpp"
#include <memory>
#include "Event.hpp"

using namespace irr;

class Core {
    public:
        Core(void);
        ~Core();

        void setupDevice(const wchar_t * const name);
        irr::scene::ISceneManager *getSceneManager(void) const;
        irr::IrrlichtDevice *getDevice(void) const;
        irr::video::IVideoDriver *getVideoDriver(void) const;
        Assets getAssets(void) const;

        void addImage(
            const Assets::FILES file,
            const float x,
            const float y
        ) const;
        gui::IGUIEditBox *addTextArea(
            const wchar_t *text,
            Assets::FILES fontPath,
            float x, float y, int width, int length
        );
        gui::IGUIStaticText *addText(
            const wchar_t *text,
            Assets::FILES fontPath,
            float x, float y, int width, int length
        );
        gui::IGUIButton *addButton(
            const wchar_t *text,
            Assets::FILES texture,
            Assets::FILES fontPath,
            float x, float y, int width, int length);

        const wchar_t *ConvertStrToW(std::string str);
        std::string ConvertWToStr(const wchar_t *wstr);
        EventReceiver _receiver;
    private:
        Assets _assets;
        irr::IrrlichtDevice *_device;

};

#endif /* !CORE_HPP_ */
