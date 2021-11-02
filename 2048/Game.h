#pragma once
#include "Board.h"
#include "Logic.h"

class Game {

public:
	Game();
private:
	void run();
	void gameSetup();
private:
	bool gameOver;
	Board board;
	std::string message;
};
