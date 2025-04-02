#include "header.h"
#include "game.h"
#include "TicTacToe.h"
#include "Gomoku.h"
#include <iostream>

using namespace std;


GameBase::GameBase(size_t width, size_t height, const string& player)
	: currentPlayer(player), board(height, vector<string>(width, " ")), maxPieceLength(1) { }

GameBase* GameBase::checkArgs(int argc, char* argv[]) {
	if (argc != expected_argc) {
		return nullptr;
	}
	string gameName = argv[input_file_name];

	if (gameName == "TicTacToe") {
		return new TicTacToe();
	}

	if (gameName == "Gomoku") {
		return new Gomoku();
	}
}

int GameBase::play() {
	cout << *this << endl;
	int turns = 0;

	while (true) {
		bool continueGame = turn();
		if (!continueGame) {
			string player = currentPlayer;
			cout << turns << " turns played. Player " << player << " quit." << endl;
			return USER_QUIT;
		} // conld not be done in turn() because it needs to check if the game is done
		turns++;

		if (done()) {
			string winner = (currentPlayer == "X") ? "O" : "X";
			
			if (dynamic_cast<TicTacToe*>(this)) {
				cout << "Player " << winner << " wins!" << endl;
			} 
			else if (dynamic_cast<Gomoku*>(this)) {
				string gomokuWinner = (winner == "X") ? "B" : "W";
				cout << "Player " << gomokuWinner << " wins!" << endl;
			} 
			else { // 我担心有一些特殊情况
				cout << "Player " << winner << " wins!" << endl;
			}
			
			return SUCCESS;
		}

		if (draw()) {
			cout << turns << " turns played. No winning moves remain. It's a draw." << endl;
			return DRAW_END;
		}
	}
}

ostream& operator<<(ostream& os, const GameBase& game) {
	game.print(os);
	return os;
}