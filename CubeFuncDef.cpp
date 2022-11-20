#include "Cube.h"
#include <iostream>

Cube::Cube(double length) {
	length_=length;
	std::cout << "The cube with length: " << length << " is initialized" << std::endl;
}

double Cube::getVolume() const {
	return length_ * length_ * length_;
}

double Cube::getSurfaceArea() const {
	return 6 * length_ * length_;
}
double Cube::getLength() const {
	return length_;
}