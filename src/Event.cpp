/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Event
*/

#include "Event.hpp"

EventReceiver::EventReceiver(void)
{
    for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

EventReceiver::~EventReceiver(void)
{
}

bool EventReceiver::OnEvent(const SEvent &event)
{
    // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return (false);
}

bool EventReceiver::IsKeyDown(EKEY_CODE keyCode) const
{
     // This is used to check whether a key is being held down
    return (KeyIsDown[keyCode]);
}
