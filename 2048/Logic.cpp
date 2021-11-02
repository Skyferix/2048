#include "Logic.h"

bool Logic::checkMovePossible(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board)
{
	return checkBorders(nextRow, nextCol) && checkMoveFields(i, j, nextRow, nextCol, board);
}

bool Logic::checkMergePossible(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board)
{
	return checkBorders(nextRow, nextCol) && checkBouthFields(i, j, nextRow, nextCol, board);
}

bool Logic::checkDirection(char direction){
	if (direction == 'a' || direction == 'w' || direction == 's' || direction == 'd')
		return true;
	return false;
}

bool Logic::checkBorders(int nextRow, int nextCol)
{
	if (nextRow < 0 || nextRow > 3 || nextCol < 0 || nextCol>3)
		return false;
	return true;
}

bool Logic::checkBouthFields(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board)
{
	if (board[i][j] != board[nextRow][nextCol] && board[nextRow][nextCol] != 0 || board[i][j] == 0)
		return false;
	return true;
}

bool Logic::checkMoveFields(int i, int j, int nextRow, int nextCol, std::vector<std::vector<int>> board)
{
	if (board[nextRow][nextCol] != 0 || board[i][j] == 0)
		return false;
	return true;
}

bool Logic::checkLose(std::vector<std::vector<int>> board)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] == 0)
				count++;
	return count == 0;
}

bool Logic::checkWin(std::vector<std::vector<int>> board)
{
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++) 
			if (board[i][j] == 2048) 
				return true;
	return false;
}