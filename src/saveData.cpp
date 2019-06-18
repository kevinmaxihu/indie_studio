//
// EPITECH PROJECT, 2019
// kevin
// File description:
// cpp
//

#include "saveData.hpp"

Save::Save()
{
    initLoadable();
}

Save::~Save(){}

void Save::printName()
{
    for (auto i = _name.rbegin(); i != _name.rend(); ++i)
        std::cout << *i << std::endl;
}

bool Save::loadData(std::string player_name)
{
    if (_loaded == false && player_name.compare("Enter Name")) {
        for (int i = 0; i != _name.size(); ++i) {
            if (!_name.at(i).compare(player_name)) {
                std::cout << "player exist" << std::endl;
                _loaded == true;
                return true;
            }
        }
    } else {
        std::cout << "No match for this user" << std::endl;
        return false;
    }
}

void Save::initLoadable()
{
    DIR *dir = opendir(".data");
    int i = 0;

    if (dir == NULL) {
        std::cerr << "Error: Can't find loadable data" << std::endl;
        exit(84);
    }
    struct dirent *enter;

    while((enter  = readdir(dir)) != NULL) {
        std::string str(".data/");

        str.append(enter->d_name);
        if (!str.compare(".data/.") || !str.compare(".data/.."))
            continue;
        std::string str2(enter->d_name);

        _name.push_back(str2);
        _loadablePath.push_back(str);
    }
    closedir(dir);
    _loaded = false;
}
