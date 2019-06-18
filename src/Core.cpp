/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Core
*/

#include "Core.hpp"
#include "Cursor.hpp"
#include "Event.hpp"

Core::Core(void)
{
    this->_assets.checkFiles();
}

Core::~Core()
{
}

void Core::setupDevice(const wchar_t * const name)
{
    this->_device = irr::createDevice(
        irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(1920, 1080),
        32, false, true, false, &_receiver);

    this->_device->setWindowCaption(name);
    this->_device->getSceneManager()->addCameraSceneNode(
        0,
        irr::core::vector3df(0, 0, 0),
        irr::core::vector3df(5, 0, 0)
    );
    this->_device->getSceneManager()->saveScene("test");
}

void Core::addImage(const Assets::FILES file, const float x, const float y) const
{
    this->_device->getGUIEnvironment()->addImage(
        this->_device->getVideoDriver()->getTexture(
            this->_assets.getFile(file).c_str()
        ), core::position2d<irr::s32>(x, y)
    );
}

gui::IGUIStaticText *Core::addText(
    const wchar_t *text,
    Assets::FILES fontPath,
    float x, float y, int width, int length
) {
    gui::IGUIStaticText *texte = this->_device->getGUIEnvironment()->addStaticText(
        text,
        core::rect<s32>(x, y, width, length), true, true, 0, -1, true);
    gui::IGUIFont *font = this->_device->getGUIEnvironment()->getFont(
        this->_assets.getFile(fontPath).c_str());
    texte->setOverrideFont(font);
    return (texte);
}

gui::IGUIEditBox *Core::addTextArea(
    const wchar_t *text,
    Assets::FILES fontPath,
    float x, float y, int width, int length)
{
    gui::IGUIFont *font = this->_device->getGUIEnvironment()->getFont(
        this->_assets.getFile(fontPath).c_str());
    gui::IGUIEditBox *editBox = this->_device->getGUIEnvironment()->addEditBox(
    text, core::rect<s32>(x,y,width,length));
    editBox->setOverrideFont(font);
    return (editBox);
}

gui::IGUIButton *Core::addButton(
    const wchar_t *text,
    Assets::FILES texture,
    Assets::FILES fontPath,
    float x, float y, int width, int length)
{
    gui::IGUIFont *font = this->_device->getGUIEnvironment()->getFont(
        this->_assets.getFile(fontPath).c_str());

    gui::IGUIButton *button = this->_device->getGUIEnvironment()->
        addButton(
            core::rect<irr::s32>(x, y, width, length), 0, -1, text
        );
    button->setImage(this->_device->getVideoDriver()->getTexture(
        this->_assets.getFile(texture).c_str())
    );
    button->setOverrideFont(font);
    return (button);
}

irr::scene::ISceneManager *Core::getSceneManager(void) const
{
    return (this->_device->getSceneManager());
}

irr::IrrlichtDevice *Core::getDevice(void) const
{
    return (this->_device);
}

irr::video::IVideoDriver *Core::getVideoDriver(void) const
{
    return (this->_device->getVideoDriver());
}

Assets Core::getAssets(void) const
{
    return (this->_assets);
}

const wchar_t *Core::ConvertStrToW(std::string str)
{
    return (std::wstring(str.begin(), str.end()).c_str());
}

std::string Core::ConvertWToStr(const wchar_t *wstr)
{
    std::wstring ws(wstr);
    std::string str(ws.begin(), ws.end());
    return (str);
}