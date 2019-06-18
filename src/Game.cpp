/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#include <memory>
#include "Game.hpp"
#include "Cursor.hpp"
#include "saveData.hpp"

Game::Game()
{
    this->_corePtr = new Core();
    this->_assets = std::shared_ptr<Assets>(new Assets());
    this->_core = std::shared_ptr<Core>(this->_corePtr);
    this->_menu = std::shared_ptr<Menu>(new Menu(this->_corePtr));
    this->_perso = std::shared_ptr<Character>(new Character(this->_corePtr));
    this->_map = std::shared_ptr<Map>(new Map());
    this->_sound = std::shared_ptr<Sound>(new Sound());
}

Game::~Game()
{
}

void Game::InitAll()
{
    this->_tmp = true;
    _menu->MenuInit();
    core::vector3df pos1(70.0f, 120.0f, 0.0f);
    core::vector3df pos2(70.0f, 0.0f, 40.0f);
    _perso->CreateCameraNode(pos1, pos2);
    _perso->Create_characterOne(_assets->getFile(Assets::FILES::PLAYER1_3D).c_str(), _assets->getFile(Assets::FILES::PLAYER1_TEX).c_str());
    _perso->Create_characterTwo(_assets->getFile(Assets::FILES::PLAYER2_3D).c_str(), _assets->getFile(Assets::FILES::PLAYER2_TEX).c_str());

    _perso->getPosition(_map->getMap(), '1');
}

void Game::begin()
{
    std::string mapAsset = _assets->getFile(Assets::FILES::MAP);
    _map->init(mapAsset);
    _core->setupDevice(L"INDIE STUDIO");
    core::vector3d<int> color = {80, 80, 80};
    Cursor myCursor = Cursor(_core->getDevice(), "assets/cursor.png");
    InitAll();
    _map->link_map(_corePtr);
    _sound->play(Sound::PLAYLIST::MENU_S, true);
    u32 starting_time = _core->getDevice()->getTimer()->getTime();
    Save save;
    _menu->setSound(_sound);
    while (_core->getDevice()->run()) {
        const u32 now = _core->getDevice()->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - starting_time) / 1000.f;

        starting_time = now;
        _core->getDevice()->getVideoDriver()->beginScene(
            true,
            true,
            irr::video::SColor(255, color.X, color.Y, color.Z)
            );
        _menu->menuRun(color);
        if (_menu->get_page() == (int)BUTTON::PLAY) {
            _sound->stop(Sound::PLAYLIST::MENU_S);
            _sound->play(Sound::PLAYLIST::GAME_S, true);
            save.loadData(_menu->getName());
            if (_core->_receiver.IsKeyDown(KEY_ESCAPE)) {
                _sound->stop(Sound::PLAYLIST::GAME_S);
                _sound->play(Sound::PLAYLIST::EXIT_S, false);
                sleep(2);
                break;
            }
            if (_core->_receiver.IsKeyDown(KEY_SPACE)) {
                _map->PutBomb(_corePtr, _perso->getCharacterOne()->getPosition());
            }
            Movement_Player_One(starting_time, now, frameDeltaTime);
            Movement_Player_Two(starting_time, now, frameDeltaTime);
            _core->getDevice()->getGUIEnvironment()->clear();
            _menu->startGame();
            _core->getDevice()->getSceneManager()->drawAll();
        } else if (_menu->get_page() == (int)BUTTON::EXIT) {
            break;
        }
        _core->getDevice()->getGUIEnvironment()->drawAll();
        myCursor.drawCursor();
        _core->getDevice()->getVideoDriver()->endScene();
    }
    _core->getDevice()->drop();
}

void Game::Movement_Player_One(u32 starting_time, const u32 now, const f32 frameDeltaTime)
{
    const f32 MOVEMENT_SPEED = 40.f;
    core::vector3df nodePosition = _perso->getCharacterOne()->getPosition();
    std::vector<int> pos = _perso->getPosition(_map->getMap(), '1');
    f32 later = _core->getDevice()->getTimer()->getTime();
    int x = pos.at(0);
    int z = pos.at(1);

    // printf("later = %d\ntmp2 = %d\n", later, _tmp2 + 5000.f);

    if (!_core->_receiver.IsKeyDown(KEY_KEY_Z) && !_core->_receiver.IsKeyDown(KEY_KEY_Q)
    && !_core->_receiver.IsKeyDown(KEY_KEY_S) && !_core->_receiver.IsKeyDown(KEY_KEY_D))
        _map->display(_map->getMap());
        _perso->one_not_walking();
    if (_core->_receiver.IsKeyDown(KEY_KEY_Z) && _perso->is_movable(_map->getMap().at(z - 1)[x])) {
        nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
        if (later > _tmp2) {
            _map->setMap(_perso->move_up(_map->getMap(), '1'));
            _tmp2 = later + 120.f;
        }
        _perso->getCharacterOne()->setRotation(core::vector3df(0, 180, 0));
        _perso->one_is_walking();
    } else if (_core->_receiver.IsKeyDown(KEY_KEY_S)  && _perso->is_movable(_map->getMap().at(z + 1)[x])) {
        if (later > _tmp2) {
            _map->setMap(_perso->move_down(_map->getMap(), '1'));
            _tmp2 = later + 120.f;
        }
        nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
        _perso->getCharacterOne()->setRotation(core::vector3df(0, 0, 0));
        _perso->one_is_walking();
    } else if (_core->_receiver.IsKeyDown(KEY_KEY_Q)  && _perso->is_movable(_map->getMap().at(z)[x - 1])) {
        if (later > _tmp2) {
            _map->setMap(_perso->move_left(_map->getMap(), '1'));
            _tmp2 = later + 120.f;
        }
        nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        _perso->getCharacterOne()->setRotation(core::vector3df(0, 90, 0));
        _perso->one_is_walking();
    } else if (_core->_receiver.IsKeyDown(KEY_KEY_D)  && _perso->is_movable(_map->getMap().at(z)[x + 1])) {
        if (later > _tmp2) {
            _map->setMap(_perso->move_right(_map->getMap(), '1'));
            _tmp2 = later + 120.f;
        }
        nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
        _perso->getCharacterOne()->setRotation(core::vector3df(0, -90, 0));
        _perso->one_is_walking();
    }
    _perso->getCharacterOne()->setPosition(nodePosition);
}

void Game::Movement_Player_Two(u32 starting_time, const u32 now, const f32 frameDeltaTime)
{
    const f32 MOVEMENT_SPEED = 40.f;
    core::vector3df nodePosition = _perso->getCharacterTwo()->getPosition();
    int y = 0;
    int x = 0;

    if (!_core->_receiver.IsKeyDown(KEY_KEY_O) && !_core->_receiver.IsKeyDown(KEY_KEY_L)
    && !_core->_receiver.IsKeyDown(KEY_KEY_K) && !_core->_receiver.IsKeyDown(KEY_KEY_M))
        _perso->two_not_walking();
    if (_core->_receiver.IsKeyDown(KEY_KEY_O)) {
        nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
        _perso->getCharacterTwo()->setRotation(core::vector3df(0, 180, 0));
        _perso->two_is_walking();
    } else if (_core->_receiver.IsKeyDown(KEY_KEY_L)) {
        nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
        _perso->getCharacterTwo()->setRotation(core::vector3df(0, 0, 0));
        _perso->two_is_walking();
    } else if (_core->_receiver.IsKeyDown(KEY_KEY_K)) {
        nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        _perso->getCharacterTwo()->setRotation(core::vector3df(0, 90, 0));
        _perso->two_is_walking();
    } else if (_core->_receiver.IsKeyDown(KEY_KEY_M)) {
        nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
        _perso->getCharacterTwo()->setRotation(core::vector3df(0, -90, 0));
        _perso->two_is_walking();
    }
     _perso->getCharacterTwo()->setPosition(nodePosition);
}

std::shared_ptr<Core> Game::GetCore()
{
    return (_core);
}
