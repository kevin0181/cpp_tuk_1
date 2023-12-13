#include<iostream>
#include "tree.h"
#include <random>

std::default_random_engine dreTree;
std::uniform_int_distribution<int> heightUid{ 0,100 };

Tree::Tree() {
	height = heightUid(dreTree);
}

void Tree::render()const {
	std::cout << "Tree - height : "<< height << std::endl;
}