#pragma once
#include "Stack.h"
#include <vector>
#include <iostream>
#include <ostream>

class Game {

public:
	Game();
	void solve();
	friend std::ostream& operator<<(std::ostream& os, const Game& game);
private:
	std::vector<Stack> stacks_;

private:
	void move_(unsigned index1, unsigned index2);
	void legalmove_(unsigned index1, unsigned index2);
};