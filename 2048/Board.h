#pragma once
#include <iostream>
#include <vector>


class Board {
public:			//contructor
	Board();
	Board(int height, int width);
public:			//public methods
	void drawBoard();
	void addCells(int firstRow, int firstCol, int secondRow, int secondCol);
	void drawNumber(int row, int col);
	void moveCell(int firstRow, int firstCol, int secondRow, int secondCol);
	void displayMessage(std::string message);

	std::vector<std::vector<int>> getBoard();

private:
	void createBoard();
	void fillBoard();
	void clearScreen();
	void drawGrid();
	void drawLegend();
	void nulifyCell(int row, int col);
private:
	int height;
	int width;
	std::vector<std::vector<int>> board;
};