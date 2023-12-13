//-----------------------------------------------------------------------------
// Tree.cpp
//-----------------------------------------------------------------------------
#include <iostream>
#include <random>
#include "game.h"
#include "tree.h"

std::default_random_engine dreTree{ 202203 };
std::uniform_int_distribution<> uiHeight( 1, 100 );			// 나무의 높이

Tree::Tree() 
{
	height = uiHeight( dreTree );
}

void Tree::render() const 
{
	std::cout << "나무    , 높이 - " << height << std::endl;
}
