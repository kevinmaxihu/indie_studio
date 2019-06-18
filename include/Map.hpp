/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <string>
#include "Assets.hpp"
#include "Core.hpp"
#include <irrlicht/irrlicht.h>

using namespace irr;

class Map {
    public:
        Map();
        ~Map();

        irr::scene::ISceneNode *creatObj(
                const core::vector3df &, const core::vector3df &, scene::ISceneManager *,
                const std::string &,const std::string &, scene::ISceneNode *scene);

        irr::scene::ISceneNode *creatSquare(
                const core::vector3df &, const core::vector3df &, scene::ISceneManager *,
                const std::string &, scene::ISceneNode *scene);

        void PutBomb(Core *_core, core::vector3df pos);
        void link_map(Core *_core);
        void display(std::vector<std::string> map);
        void init(const std::string &mapAsset);
        std::vector<std::string> getMap();
        void setMap(std::vector<std::string> newmap);
    protected:
    private:
        
        Assets _assets;
        std::vector<std::string> _map;
        scene::ISceneManager *_smgr;
        video::IVideoDriver *_driver;
};

#endif /* !MAP_HPP_ */
