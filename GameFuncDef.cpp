#include "Game.h"
#include <iostream>

Game::Game() {
	for (int i = 0; i < 3; i++) {
		Stack StackOfCubes;
		std::cout << i << std::endl;
		stacks_.push_back(StackOfCubes);
	}

	Cube TheBiggestOne(4.0);
	stacks_[0].push_back(TheBiggestOne);

	Cube TheBigOne(3.0);
	stacks_[0].push_back(TheBigOne);

	Cube TheMediumOne(2.0);
	stacks_[0].push_back(TheMediumOne);

	Cube TheSmallestOne(1.0);
	stacks_[0].push_back(TheSmallestOne);
}

void Game::move_(unsigned index1, unsigned index2) {
	Cube chosencube = stacks_[index1].removeTop();
	stacks_[index2].push_back(chosencube);
}

void Game::legalmove_(unsigned index1, unsigned index2) {
	if (stacks_[index1].size() == 0 && stacks_[index2].size() > 0) {
		move_(index2, index1);
	}
	else if (stacks_[index1].size() > 0 && stacks_[index2].size() == 0) {
		move_(index1, index2);
	}
	else if (stacks_[index1].size() > 0 && stacks_[index2].size() > 0) {
		if (stacks_[index2].peekTop().getLength() > stacks_[index1].peekTop().getLength()) {
			move_(index1, index2);
		}
		else {
			move_(index2, index1);
		}
	}
	std::cout << *this << std::endl;
}

void Game::solve() {
	while (stacks_[2].size() != 4) {
		legalmove_(0, 1);
		legalmove_(0, 2);
		legalmove_(2, 1);
	}
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
	for (unsigned i = 0; i < game.stacks_.size(); i++) {
		os << "Stack[" << i << "]: " << game.stacks_[i];
	}
	return os;
}