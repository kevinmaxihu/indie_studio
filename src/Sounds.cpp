//
// EPITECH PROJECT, 2019
// cpp sound sfml
// File description:
// epitech
//

#include "Sounds.hpp"

Sound::Sound()
{
    init_buffer();
    init_sound();
    init_bool();
}

Sound::~Sound(){};

void Sound::play(PLAYLIST name, bool loop)
{
    int tmp = (int)name;

    if (tmp == 4) {
        _sound.at(tmp).play();
//        reset_click();
    }else if (_status.at(tmp) == false && _pauseStatus.at(tmp) == true) {
        _sound.at(tmp).play();
        if (loop == true)
            _sound.at(tmp).setLoop(true);
        else
            _sound.at(tmp).setLoop(false);
        _status.at(tmp) = true;
        _pauseStatus.at(tmp) == false;
    } else if (_status.at(tmp) == false && _pauseStatus.at(tmp) == false) {
        _sound.at(tmp).play();
        if (loop == true)
            _sound.at(tmp).setLoop(true);
        else
            _sound.at(tmp).setLoop(false);
        _status.at(tmp) = true;
    }
}

void Sound::stop(PLAYLIST name)
{
    int tmp = (int)name;

    if (_status.at(tmp) == true) {
        _sound.at(tmp).stop();
        _status.at(tmp) = false;
    }
}

void Sound::pause(PLAYLIST name)
{
    int tmp = (int)name;

    if (_pauseStatus.at(tmp) ==  false && _status.at(tmp) == true) {
        _sound.at(tmp).pause();
        _pauseStatus.at(tmp) = true;
        _status.at(tmp) = false;
    }
}

void Sound::volume(/*PLAYLIST name,*/ float how)
{
//    int tmp = (int)name;
    _volume = how;
    if (_volume < 0)
        _volume = 0;
    if (_volume > 100)
        _volume = 100;
    for (int i = 0 ; i != _sound.size(); i++)
        _sound.at(i).setVolume(_volume);
}

void Sound::setVolume(PLAYLIST name, float volume)
{
    int tmp = (int)name;

    _sound.at(tmp).setVolume(volume);
    _volume = volume;
}

float Sound::getVolume()
{
    return _volume;
}

void Sound::init_buffer()
{
    sf::SoundBuffer _buffer_0;
    sf::SoundBuffer _buffer_1;
    sf::SoundBuffer _buffer_2;
    sf::SoundBuffer _buffer_3;
    sf::SoundBuffer _buffer_4;
    sf::SoundBuffer _buffer_5;
    sf::SoundBuffer _buffer_6;

    _buffer.push_back(_buffer_0);
    _buffer.push_back(_buffer_1);
    _buffer.push_back(_buffer_2);
    _buffer.push_back(_buffer_3);
    _buffer.push_back(_buffer_4);
    _buffer.push_back(_buffer_5);
    _buffer.push_back(_buffer_6);
    for (int i = 0; i != _filesPath.size(); i++) {
        _buffer.at(i).loadFromFile(_filesPath.at(i));
        if (!_buffer.at(i).loadFromFile(_filesPath.at(i))) {
            std::cerr << "Sound: Error loading sound Buffering ";
            std::cerr << "Sound is called :" << _filesPath.at(i) << std::endl;
            exit(84);
        }
    }
}

void Sound::init_sound()
{
    sf::Sound sound_0;
    sf::Sound sound_1;
    sf::Sound sound_2;
    sf::Sound sound_3;
    sf::Sound sound_4;
    sf::Sound sound_5;
    sf::Sound sound_6;

    _sound.push_back(sound_0);
    _sound.push_back(sound_1);
    _sound.push_back(sound_2);
    _sound.push_back(sound_3);
    _sound.push_back(sound_4);
    _sound.push_back(sound_5);
    _sound.push_back(sound_6);
    for (int i = 0; i != _filesPath.size(); i++) {
        _sound.at(i).setBuffer(_buffer.at(i));
        _sound.at(i).setVolume(25.f);
    }
    _volume = 25;
}

void Sound::reset_click()
{
    sf::SoundBuffer tmp_buffer;
    sf::Sound tmp_sound;

    if (!tmp_buffer.loadFromFile(_filesPath.at(4))) {
        std::cerr << "Sound Error loading buffer in reset_click: ";
        std::cerr << _filesPath.at(4) << " file" << std::endl;
    }
    tmp_sound.setBuffer(tmp_buffer);
    _click = tmp_sound;
}

void Sound::init_bool()
{
    _status = {
        false,
        false,
        false,
        false,
        false,
        false,
        false
    };
    _pauseStatus = {
        false,
        false,
        false,
        false,
        false,
        false,
        false
    };
}
