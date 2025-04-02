#include "header.h"
#include "game.h"
#include <iostream>

using namespace std;


GameBase::GameBase() : currentPlayer("X"), board(5, vector<string>(5, " ")) {}

int GameBase::play() {
	cout << *this << endl;
	int turns = 0;

	while (true) {
		bool continueGame = turn();
		if (!continueGame) {
			string player = currentPlayer;
			cout << turns << " turns played. Player " << player << "quit." << endl;
			return USER_QUIT;
		}
		turns++;

		if (done()) {
			string winner = (currentPlayer == "X") ? "O" : "X";
			cout << "Player " << winner << " wins!" << endl;
			return SUCCESS;
		}

		if (draw()) {
			cout << turns << " turns played. No winning moves remain. It's a draw." << endl;
			return DRAW_END;
		}
	}
}