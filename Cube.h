#pragma once

class Cube{

	public:
		Cube(double length);

		double getVolume() const;

		double getLength() const;
		double getSurfaceArea() const;
	private:
		double length_{};
};