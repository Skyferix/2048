#pragma once
#include <conio.h>
#include "Logic.h"
#include "Board.h"

class Actions {
public:
	static char chooseDirection();
	static void move(char direction, Board& board);
	static void addPiece(Board& board);
private:
	static int getDirectionNumber(char direction);
	static std::pair<int, int> findEmptyCell(std::vector<std::vector<int>> board);
	static bool slide(int direction, Board& board);
	static bool merge(int direction, Board& board);
private:
	static int gridRow[];
	static int gridCol[];
};