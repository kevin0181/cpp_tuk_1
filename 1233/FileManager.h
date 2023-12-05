//
// Created by 유영빈 on 2023/12/05.
//

#ifndef INC_2_FILEMANAGER_H
#define INC_2_FILEMANAGER_H

#include <iostream>
#include "ShapeManager.h"


class FileManager {
    ShapeManager &sm;
    Shape **fShapes;
public:

    FileManager(ShapeManager &);

    ~FileManager();

    void saveFile(std::string);

    void readFile(std::string);
};


#endif //INC_2_FILEMANAGER_H
