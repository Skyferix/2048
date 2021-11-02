#include "Game.h"
#include "Actions.h"

Game::Game()
{
	gameOver = false;
	board = Board(4, 4);
	run();
}

void Game::run()
{
	gameSetup();
	while (!gameOver) {
		board.drawBoard();
		char direction = Actions::chooseDirection();
		Actions::move(direction, board);
		if (Logic::checkWin(board.getBoard())) {
			gameOver = true;
			message = "You have won";
		}
		else if (Logic::checkLose(board.getBoard())) {
			gameOver = true;
			message = "You have lost";
		}
	}
	board.displayMessage(message);
}

void Game::gameSetup()
{
	srand(time(NULL));
	Actions::addPiece(board);   //adding first piece to the board
}
