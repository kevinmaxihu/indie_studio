/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Menu.hpp"
#include "Core.hpp"
#include "Character.hpp"
#include "Assets.hpp"
#include "Map.hpp"
#include "Event.hpp"
#include "Sounds.hpp"
#include <memory>
#include <iostream>
#include <unistd.h>

class Menu;
class Game {
	enum class BUTTON {
		PLAY = 200,
		EXIT = 99
	};
	public:
		Game();
		~Game();

		void InitAndChara();
		void begin();
		void Movement_Player_One(u32 starting_time, const u32 now, const f32 frameDeltaTime);
		void Movement_Player_Two(u32 starting_time, const u32 now, const f32 frameDeltaTime);
		void InitAll();
		std::shared_ptr<Core> GetCore();
	protected:
	private:
		Core *_corePtr;
		std::shared_ptr<Menu> _menu;
		std::shared_ptr<Core> _core;
		std::shared_ptr<Character> _perso;
		std::shared_ptr<Assets> _assets;
		std::shared_ptr<Map> _map;
		std::shared_ptr<Sound> _sound;
		bool _tmp;
		f32 _tmp2;
};

#endif /* !GAME_HPP_ */
