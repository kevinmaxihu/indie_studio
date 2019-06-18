/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#include <fstream>
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <string.h>
#include "Map.hpp"
#include "Core.hpp"
#include "Assets.hpp"
#include "Exception.hpp"

Map::Map()
{
}

Map::~Map()
{
}

void Map::display(std::vector<std::string> map)
{
    int x = 0;
    int y = 0;

    while (y < map.size()) {
        if (map.at(y)[x] == '\0') {
            printf("\n");
            y += 1;
            x = 0;
        } else {
            printf("%c", map.at(y)[x]);
            x += 1;
        }
    }
}

void Map::link_map(Core *_core)
{
    _smgr = _core->getSceneManager();
    _driver = _core->getVideoDriver();
    scene::ISceneNode *_scene = _smgr->addEmptySceneNode();
    std::vector<std::string> NewMap = getMap();
    int x = 0;
    int y = 0;

    while (y < NewMap.size()) {
        if (NewMap.at(y)[x] == '\0') {
            y += 1;
            x = 0;
        } else {
            irr::scene::ISceneNode *bl = nullptr;
            if (NewMap.at(y)[x] == 'M') {
                // printf("WALL\n");
                bl = creatObj(core::vector3df(0.06f, 0.06f, 0.06f), core::vector3df(x * 4.9f, 4.7f, 4.9f * y),
                     _smgr, _assets.getFile(Assets::FILES::WALL3D), _assets.getFile(Assets::FILES::WALLTEX), _scene);
            } else if (NewMap.at(y)[x] == '*' || NewMap.at(y)[x] == '1' || NewMap.at(y)[x] == '2' || NewMap.at(y)[x] == '3' || NewMap.at(y)[x] == '4') {
                creatSquare(irr::core::vector3df(3.5f, 0.0f, 3.7f), irr::core::vector3df(x * 5.0f, 0, 4.9f * y), _smgr, _assets.getFile(Assets::FILES::GROUNDTEX), _scene);
            } else if (NewMap.at(y)[x] == 'C') {
                bl = creatObj(core::vector3df(0.05f, 0.05f, 0.05f), core::vector3df(x * 4.9f, 4.7f, 4.9f * y),
                     _smgr, _assets.getFile(Assets::FILES::WALL3D), _assets.getFile(Assets::FILES::WOODTEX), _scene);
            }
            x += 1;
        }
    }
}

void Map::PutBomb(Core *_core, core::vector3df pos)
{
    _smgr = _core->getSceneManager();
    _driver = _core->getVideoDriver();
    scene::ISceneNode *_scene = _smgr->addEmptySceneNode();

    irr::scene::ISceneNode *bl = creatObj(core::vector3df(15.0f, 15.0f, 15.0f), pos,
            _smgr, _assets.getFile(Assets::FILES::BOMB3D), _assets.getFile(Assets::FILES::BOMBTEX), _scene);
}

irr::scene::ISceneNode *Map::creatSquare(
        const irr::core::vector3df &scale, const irr::core::vector3df &pos, irr::scene::ISceneManager *smgr,
        const std::string &path, irr::scene::ISceneNode *scene)
{
    irr::scene::ISceneNode *news = smgr->addCubeSceneNode(4.0f, scene);

    news->setScale(scale);
    news->setPosition(pos);
    news->setMaterialTexture(0, _driver->getTexture(path.c_str()));
    news->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    return (news);
}

scene::ISceneNode *Map::creatObj(
        const core::vector3df &scale, const core::vector3df &pos, scene::ISceneManager *smgr,
        const std::string &path, const std::string &path2, scene::ISceneNode *scene)
{
    scene::ISceneNode *news = smgr->addMeshSceneNode(smgr->getMesh(path.c_str()), scene);
    news->setScale(scale);
    news->setPosition(pos);
    news->setMaterialTexture(0, _driver->getTexture(path2.c_str()));
    news->setMaterialFlag(video::EMF_LIGHTING, false);
    return (news);
}

void Map::init(const std::string &mapAsset)
{
    std::string line;
    std::vector<std::string> mapVector;
    std::ifstream myfile(mapAsset);

    if (myfile.is_open()) {
        while (getline(myfile, line))
            mapVector.push_back(line);
    } else {
        throw Exception("Map: unable to open file");
    }
    myfile.close();
    setMap(mapVector);
}

void Map::setMap(std::vector<std::string> newmap)
{
    this->_map = newmap;
}

std::vector<std::string> Map::getMap()
{
    return(this->_map);
}
