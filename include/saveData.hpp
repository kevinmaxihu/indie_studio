//
// EPITECH PROJECT, 2019
// kevin
// File description:
// hpp
//

#ifndef SAVEDATA_HPP_
#define SAVEDATA_HPP_

#include <iostream>
#include <vector>
#include <dirent.h>
#include <sys/types.h>

class Save {
public:
    Save();
    ~Save();
    void printName();
    bool loadData(std::string player_name);
//    void saveData();
//    void deleteData(std::string player_name);
//    void DataNewName(std::string old, std::string name);
private:
    void initLoadable();
    std::vector<std::string> _loadablePath;
    std::vector<std::string> _name;
    bool _loaded;
};

#endif // SAVEDATA_HPP //
