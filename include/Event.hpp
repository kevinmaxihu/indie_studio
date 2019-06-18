/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <irrlicht/irrlicht.h>
#include <string>

using namespace irr;

class EventReceiver : public IEventReceiver {
public:
    EventReceiver(void);
    ~EventReceiver(void);
    virtual bool OnEvent(const SEvent& event);
    virtual bool IsKeyDown(EKEY_CODE keyCode) const;

private:
    // We use this array to store the current state of each key
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif /* !EVENT_HPP_ */