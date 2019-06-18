/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <vector>
#include "Core.hpp"

class Character {
	public:
        Character(Core *core);
	    ~Character();

        std::vector<int> getPosition(std::vector<std::string> map, char p);
        bool is_movable(char c);
		std::vector<std::string> move_left(std::vector<std::string> map, char p);
        std::vector<std::string> move_right(std::vector<std::string> map, char p);
        std::vector<std::string> move_up(std::vector<std::string> map, char p);
        std::vector<std::string> move_down(std::vector<std::string> map, char p);

        void CreateCameraNode(core::vector3df pos1, core::vector3df pos2) const;
	    void Create_characterOne(const char *chr_file, const char *chr_text);
        void Create_characterTwo(const char *chr_file, const char *chr_text);
		void init_charachter(scene::IAnimatedMeshSceneNode *character);
        void one_is_walking();
        void one_not_walking();
        void two_is_walking();
        void two_not_walking();
		scene::IAnimatedMeshSceneNode *getCharacterOne();
        scene::IAnimatedMeshSceneNode *getCharacterTwo();
    private:
        Core *_core;
        scene::IAnimatedMeshSceneNode *_character_one;
        scene::IAnimatedMeshSceneNode *_character_two;
        bool _walk1;
        bool _walk2;
        std::string _name;
        bool _life;
        int _speed;
        int _bombsize;
        int _posx;
        int _posy;
};

#endif /* !Character_HPP_ */
