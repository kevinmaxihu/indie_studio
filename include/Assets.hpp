/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Assets
*/

#ifndef ASSETS_HPP_
#define ASSETS_HPP_

#include <vector>
#include <string>

class Assets {
    public:
        Assets();
        ~Assets();
        enum class FILES {
            BUTTON_A,
            CAVE,
            FONT_CLASSIC,
            CURSOR,
            MAP,
            OVERLAY,
            PLAYER1_3D,
            PLAYER1_TEX,
            PLAYER2_3D,
            PLAYER2_TEX,
            BACKGROUND,
            WALL3D,
            WALLTEX,
            GROUNDTEX,
            WOODTEX,
            BOMB3D,
            BOMBTEX
        };

        void checkFiles(void) const;
        std::string getFile(FILES file) const;
    private:
        std::vector<std::string> _filesPath = {
            "./assets/ButtonA.png",
            "./assets/cave.png",
            "./assets/fontlucida.png",
            "./assets/cursor.png",
            "./assets/.map1",
            "./assets/OverlayBomberman.png",
            "assets/PlayerOne.b3d",
            "assets/PlayerColorSetOne.png",
            "assets/PlayerTwo.b3d",
            "assets/PlayerColorSetTwo.png",
            "assets/arcade2.jpg",
            "assets/CoinBlock.obj",
            "assets/grey_brick.bmp",
            "assets/Grass01.bmp",
            "assets/Floor_Wdn.bmp",
            "assets/Bomb.obj",
            "assets/Albedo.png"
        };
};

#endif /* !ASSETS_HPP_ */
