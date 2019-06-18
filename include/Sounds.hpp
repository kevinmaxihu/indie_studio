//
// EPITECH PROJECT, 2019
// Sound.hpp
// File description:
// include
//

#ifndef SOUNDS_CPP_
#define SOUNDS_CPP_

#include <SFML/Audio.hpp>
#include <iostream>

class Sound {
public:
    Sound();
    ~Sound();
    enum class PLAYLIST {
        MENU_S = 0,
        GAME_S = 1,
        PAUSE_S = 2,
        BOMB_S = 3,
        CLICK_S = 4,
        EXIT_S = 5,
        EXIT2_S = 6
    };
    void play(PLAYLIST name, bool loop);
    void stop(PLAYLIST name);
    void pause(PLAYLIST name);
    void volume(/* PLAYLIST name, */float how);
    void setVolume(PLAYLIST name, float volume);
    float getVolume();
    
private:
    void init_buffer();
    void init_sound();
    void reset_click();
    void init_bool();
    std::vector<std::string> _filesPath = {
        "./assets/sounds/menu_s.wav",
        "./assets/sounds/game_s.wav",
        "./assets/sounds/pause_s.wav",
        "./assets/sounds/bomb_s.wav",
        "./assets/sounds/click_s.wav",
        "./assets/sounds/exit_s.wav",
        "./assets/sounds/exit2_s.wav"
    };
    sf::SoundBuffer _click_b;
    sf::Sound _click;
    std::vector<sf::SoundBuffer> _buffer;
    std::vector<sf::Sound> _sound;
    std::vector<bool> _status;
    std::vector<bool> _pauseStatus;
    float _volume;
};

#endif // SOUNDS_CPP_ //
