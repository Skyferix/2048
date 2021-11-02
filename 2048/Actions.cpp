#include "Actions.h"


char Actions::chooseDirection() {
	char direction;
	do {
		direction = _getch();
	} while (!Logic::checkDirection(direction));
	return direction;
}

void Actions::move(char directionChar, Board& board)
{
    int direction = getDirectionNumber(directionChar);
    bool firstSlide = slide(direction, board);
    bool numberMerge = merge(direction, board);
    bool secondSlide = slide(direction, board);
    if (firstSlide || numberMerge || secondSlide)
        addPiece(board);    
}

int Actions::getDirectionNumber(char direction)
{
    switch (direction)
    {
        case 's':
            return 0;
        case 'd':
            return 1;
        case 'w':
            return 2;
        case 'a':
            return 3;
        default:
            return 0;
    }
}

std::pair<int, int> Actions::findEmptyCell(std::vector<std::vector<int>> board)
{
    bool emptyCell = false;
    int row, col;
    std::pair<int, int> pair;
    while (!emptyCell) {
        row = rand() % 4;
        col = rand() % 4;
        if (board[col][row] == 0)
            emptyCell = true;
    }

    return std::make_pair(col, row);
}

bool Actions::slide(int direction, Board& board)
{
    int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;
    if (direction == 0) {
        startRow = 3;
        rowStep = -1;
    }
    else if (direction == 1) {
        startCol = 3;
        colStep = -1;
    }
    int movePossible = false, canAddPiece = false;
    do {
        movePossible = false;
        for (int i = startRow; i >= 0 && i < 4; i += rowStep) {
            for (int j = startCol; j >= 0 && j < 4; j += colStep) {
                int nextRow = i + gridRow[direction], nextCol = j + gridCol[direction];

                if (Logic::checkMovePossible(i, j, nextRow, nextCol, board.getBoard())) {
                    board.addCells(nextRow, nextCol, i, j);
                    movePossible = true;
                    canAddPiece = true;
                }
            }
        }
    } while (movePossible);
    return canAddPiece;
}

bool Actions::merge(int direction, Board& board)
{
    int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;
    if (direction == 0) {
        startRow = 3;
        rowStep = -1;
    }
    else if (direction == 1) {
        startCol = 3;
        colStep = -1;
    }

    int canAddPiece = false;
    for (int i = startRow; i >= 0 && i < 4; i += rowStep) {
        for (int j = startCol; j >= 0 && j < 4; j += colStep) {
            int nextRow = i + gridRow[direction], nextCol = j + gridCol[direction];

            if (Logic::checkMergePossible(i, j, nextRow, nextCol, board.getBoard())) {
                board.addCells(nextRow, nextCol, i, j);
                canAddPiece = true;
            }
        }
    }
    return canAddPiece;
}

void Actions::addPiece(Board& board)
{
    std::pair<int, int> pair = findEmptyCell(board.getBoard());
    board.drawNumber(pair.first, pair.second);
}

int Actions::gridRow[] = { 1,0,-1,0 };
int Actions::gridCol[] = { 0,1,0,-1 };
