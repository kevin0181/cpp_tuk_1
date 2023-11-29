#pragma once
#include "ShapeManager.h"

class Menu {
	ShapeManager sm{};
public:
	Menu(ShapeManager&);
	void choice(int);
};