#pragma once
#include "Cube.h"
#include <ostream>
#include <vector>
#include<iostream>

class Stack {
public:
	void push_back(const Cube& cube);
	Cube removeTop();
	Cube& peekTop();
	unsigned size() const;

private:
	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
	std::vector<Cube> cubes_;

};
