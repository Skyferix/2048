#include "Board.h"
#include <iomanip>

Board::Board() {
	Board::Board(4, 4);
}

Board::Board(int height, int width) {
	this->height = height;
	this->width = width;
	createBoard();
	fillBoard();
}

void Board::drawBoard() {
	clearScreen();
	drawGrid();
	drawLegend();
}

void Board::addCells(int firstRow, int firstCol, int secondRow, int secondCol)
{
	board[firstRow][firstCol] += board[secondRow][secondCol];
	nulifyCell(secondRow, secondCol);
}

std::vector<std::vector<int>> Board::getBoard()
{
	return board;
}

void Board::createBoard()
{
	std::vector<std::vector<int>> vec(height, std::vector<int>(width, 0));
	board = vec;
}

void Board::fillBoard()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			board[i][j] = 0;
}

void Board::clearScreen()
{
	system("cls");
}

void Board::drawGrid()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j] == 0)
				std::cout << std::setw(5) << ".";
			else
				std::cout << std::setw(5) << board[i][j];
		}
		std::cout << std::endl;
	}
}

void Board::drawLegend()
{
	std::cout << std::endl;
	std::cout << "Please enter arow a, w, s or d keys to make move: ";
}

void Board::drawNumber(int row, int col) {
	board[row][col] = 2;
}

void Board::moveCell(int firstRow, int firstCol, int secondRow, int secondCol)
{
	board[secondRow][secondRow] = board[firstRow][firstCol];
	nulifyCell(firstRow, firstCol);
}

void Board::displayMessage(std::string message)
{
	clearScreen();
	std::cout << message;
}

void Board::nulifyCell(int row, int col)
{
	board[row][col] = 0;
}

