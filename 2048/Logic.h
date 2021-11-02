#pragma once
#include <vector>

class Logic {
public:
	static bool checkMovePossible(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board);
	static bool checkMergePossible(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board);
	static bool checkDirection(char direction);
	static bool checkLose(std::vector<std::vector<int>> board);
	static bool checkWin(std::vector<std::vector<int>> board);
private:
	static bool checkBorders(int nextRow, int nextCol);
	static bool checkBouthFields(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board);
	static bool checkMoveFields(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board);
};