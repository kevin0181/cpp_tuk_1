#pragma once

#include <iostream>
#include "ShapeManager.h"
#include "FileManager.h"

class Menu {
    ShapeManager sm;
public:
    Menu(ShapeManager &);

    void qChoice();

    void choice(int);

    void qDeleteShape();

    void deleteShapeChoice(int);

    void deleteShape(Shape);

    void deleteNumber();

    int addCapacitySize();

    void saveFile();

    void readFile();
};