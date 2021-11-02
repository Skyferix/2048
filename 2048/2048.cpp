#include <iostream>
#include <ctime>
#include "Board.h"
#include <conio.h>
#include "Game.h"

const int height = 4;
const int width = 4;
int board[height][width];
int gridRow[] = { 1,0,-1,0 };
int gridCol[] = { 0,1,0,-1 };
bool gameOver = false;
void addPiece();
void fillBoard();
void drawBoard();
std::pair<int, int> findEmptyCell();
void drawNumber(int col, int row);
void moveNumbers(char direction);
void move(int direction);
bool checkBorders(int nextRow, int nextCol);
bool checkBouthFields(int i, int j, int nextRow, int nextCol);
bool checkMovePossible(int i, int j, int nextRow, int nextCol);

int main()
{
    Game game;
    /*srand(time(NULL));
    fillBoard();
    addPiece();
    while (!gameOver) {
        system("cls");        
        drawBoard();
        std::cout << std::endl;
        std::cout << "Please enter arow a, w, s or d keys to make move: ";
        char c = _getch();
        moveNumbers(c);
    }*/
}

void fillBoard() {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            board[i][j] = 0;
}

void drawBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 0)
                std::cout << ".";
            else
                std::cout << board[i][j];
            std::cout << "    ";
        }
        std::cout << std::endl;
    }
}

std::pair<int,int> findEmptyCell() {
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

void drawNumber(int col, int row) {
    board[col][row] = 2;
}

void moveNumbers(char direction) {
    switch (direction)
    {
    case 's':
        move(0);
        break;
    case 'd':
        move(1);
        break;
    case 'w':
        move(2);
        break;
    case 'a':
        move(3);
        break;
    default:
        break;
    }
}

void move(int direction) {
    int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;
    if (direction == 0) {
        startRow = 3;
        rowStep = -1;
    } else if (direction == 1) {
        startCol = 3;
        colStep = -1;
    }

    bool movePossible, canAddPiece = false;
    do {
        movePossible = false;
        for (int i = startRow; i >= 0 && i < 4; i += rowStep) {
            for (int j = startCol; j >= 0 && j < 4; j += colStep) {
                if (board[i][j] == 2) {
                    int h = 1;
                }
                int nextRow = i + gridRow[direction], nextCol = j + gridCol[direction];
                if (checkMovePossible(i, j, nextRow, nextCol)) {
                    board[nextRow][nextCol] += board[i][j];
                    board[i][j] = 0;
                    movePossible = true;
                    canAddPiece = true;
                }
            }
        }
    } while (movePossible);
    if (canAddPiece) {
        addPiece();
    }
    
}

bool checkMovePossible(int i, int j, int nextRow, int nextCol) {
    return checkBorders(nextRow, nextCol) && checkBouthFields(i, j, nextRow, nextCol);
}

bool checkBorders(int nextRow, int nextCol) {
    if (nextRow < 0 || nextRow > 3 || nextCol < 0 || nextCol>3)        
        return false;
    return true;
}

bool checkBouthFields(int i, int j, int nextRow, int nextCol) {
    if (board[i][j] != board[nextRow][nextCol] && board[nextRow][nextCol] != 0 || board[i][j] == 0)
        return false;
    return true;
}

void addPiece() {
    std::pair<int, int> pair = findEmptyCell();
    drawNumber(pair.first, pair.second);
}