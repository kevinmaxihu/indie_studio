/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(Core *core)
{
    this->_core = core;
}

Character::~Character()
{
}

std::vector<int> Character::getPosition(std::vector<std::string> map, char p)
{
    int x = 0;
    int y = 0;
    std::vector<int> pos;

    while (y < map.size()) {
        if (map.at(y)[x] == '\0') {
            y += 1;
            x = 0;
        } else if (map.at(y)[x] == p) {
            break;
        } else {
            x += 1;
        }
    }
    this->_posx = x;
    this ->_posy = y;
    pos.push_back(x);
    pos.push_back(y);
    return (pos);
}

bool Character::is_movable(char c)
{
    if (c == 'M')
        return (false);
    return (true);
}


void Character::Create_characterOne(const char *chr_file, const char *chr_text)
{
    this->_character_one =
        _core->getDevice()->getSceneManager()->addAnimatedMeshSceneNode (
            _core->getDevice()->getSceneManager()->getMesh(chr_file), 0, -1,
            core::vector3df(7.0f, 0.0f, 95.0f), core::vector3df(0.0f, 0.0f, 0.0f), core::vector3df(4.0f, 4.0f, 4.0f));
    this->_character_one->setMaterialFlag(
        video::EMF_LIGHTING, false);
    this->_character_one->setMaterialTexture(
        0, _core->getDevice()->getVideoDriver()->getTexture(chr_text));
}

scene::IAnimatedMeshSceneNode *Character::getCharacterOne()
{
    return(this->_character_one);
}

void Character::Create_characterTwo(const char *chr_file, const char *chr_text)
{
    this->_character_two =
        _core->getDevice()->getSceneManager()->addAnimatedMeshSceneNode (
            _core->getDevice()->getSceneManager()->getMesh(chr_file), 0, -1,
            core::vector3df(80.0f, 0.0f, 95.0f), core::vector3df(0.0f, 0.0f, 0.0f), core::vector3df(4.0f, 4.0f, 4.0f));
    this->_character_two->setMaterialFlag(
        video::EMF_LIGHTING, false);
    this->_character_two->setMaterialTexture(
        0, _core->getDevice()->getVideoDriver()->getTexture(chr_text));
}

scene::IAnimatedMeshSceneNode *Character::getCharacterTwo()
{
    return(this->_character_two);
}

void Character::CreateCameraNode(core::vector3df pos1, core::vector3df pos2) const
{
    _core->getSceneManager()->addCameraSceneNode(0, pos1, pos2, true);
}

std::vector<std::string> Character::move_left(std::vector<std::string> map, char p)
{
    getPosition(map, p);
    if (_posx > 0 && is_movable(map.at(_posy)[_posx - 1])) {
        map.at(_posy)[_posx] = map.at(_posy)[_posx - 1];
        map.at(_posy)[_posx - 1] = p;
    }
    return (map);
}

std::vector<std::string> Character::move_right(std::vector<std::string> map, char p)
{
    getPosition(map, p);
    if (_posx > 0 && is_movable(map.at(_posy)[_posx + 1])) {
        map.at(_posy)[_posx] = map.at(_posy)[_posx + 1];
        map.at(_posy)[_posx + 1] = p;
    }
    return (map);
}

std::vector<std::string> Character::move_up(std::vector<std::string> map, char p)
{
    getPosition(map, p);
    if (_posy > 0 && is_movable(map.at(_posy - 1)[_posx])) {
        map.at(_posy)[_posx] = map.at(_posy - 1)[_posx];
        map.at(_posy - 1)[_posx] = p;
    }
    return (map);
}

std::vector<std::string> Character::move_down(std::vector<std::string> map, char p)
{
    getPosition(map, p);
    if (_posx > 0 && is_movable(map.at(_posy + 1)[_posx])) {
        map.at(_posy)[_posx] = map.at(_posy + 1)[_posx];
        map.at(_posy + 1)[_posx] = p;
    }
    return (map);
}

void Character::one_is_walking()
{
    if (_walk1 == 0) {
        _character_one->setFrameLoop(0, 80);
        _character_one->setAnimationSpeed(60);
    }

    _walk1 = 1;
}

void Character::one_not_walking()
{
    if (_walk1 == 1) {
        _character_one->setFrameLoop(90, 130);
        _character_one->setAnimationSpeed(30);
    }
    _walk1 = 0;
}

void Character::two_is_walking()
{
    if (_walk2 == 0) {
        _character_two->setFrameLoop(0, 80);
        _character_two->setAnimationSpeed(60);
    }

    _walk2 = 1;
}

void Character::two_not_walking()
{
    if (_walk2 == 1) {
        _character_two->setFrameLoop(90, 130);
        _character_two->setAnimationSpeed(30);
    }
    _walk2 = 0;
}