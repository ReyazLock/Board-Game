#include "header.h"
#include "TicTacToe.h"
#include "game.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//  set the size of the board and the first player (X)
TicTacToe::TicTacToe() : GameBase(5, 5, "X") {}

//  From the four directions to determine whether the victory conditions are met
bool TicTacToe::done() const {
	//  check horizontal
	for (int y = 1; y < 4; y++) {
		if (board[y][1] != " " && board[y][1] == board[y][2] && board[y][1] == board[y][3]) {
			return true;
		}
	}

	//  check vertical
	for (int x = 1; x < 4; x++) {
		if (board[1][x] != " " && board[1][x] == board[2][x] && board[2][x] == board[3][x]) {
			return true;
		}
	}

	//  check diagonal down-right
	if (board[1][1] != " " && board[1][1] == board[2][2] && board[1][1] == board[3][3]) {
		return true;
	}

	//  check diagonal down-left
	if (board[1][3] != " " && board[1][3] == board[2][2] && board[1][3] == board[3][1]) {
		return true;
	}

	return false;
}

//  Determine if the game is a draw
bool TicTacToe::draw() const {
	if (done()) {
		return false;
	}

	//check the inner 3x3 board
	for (int y = 1; y < 4; y++) {
		for (int x = 1; x < 4; x++) {
			if (board[y][x] == " ") {
				return false;  // an empty cell, not draw
			}
		}
	}

	return true; // all inner board are fixed and game is not done
}

//  Print the information for each turn and determine if the input is correct
bool TicTacToe::prompt(unsigned int& x, unsigned int& y) {
	string input;

	while (true) {
		cout << "Enter 'quit' or coordinates (x, y) between 1 ~ 3: ";
		getline(cin, input);

		if (input == "quit") {
			return false;
		}

		replace(input.begin(), input.end(), ',', ' ');
		istringstream iss(input);

		if (iss >> x >> y) {
			char remain;
			if (iss >> remain) {
				cout << "Invalid input: extra characters after coordinates." << endl;
			}
			else {
				if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
					return true;
				}
				else {
					cout << "Coordinates must be between 1 and 3, please try again." << endl;
				}
			}
		}
		else {
			cout << "Invalid input. Please enter coordinates as x, y or 'quit'." << endl;
		}
	}
}

//  Determine the current turn, the position of the piece, and whether the position of the piece is compliant
bool TicTacToe::turn() {
	cout << "Player " << currentPlayer << "'s turn." << endl;  // current player info

	while (true) {
		unsigned int x, y;
		bool continueGame = prompt(x, y);

		if (!continueGame) {
			return false;
		}

		if (board[y][x] == " ") {  //  Determines whether the point of the piece is empty
			setPiece(x, y, currentPlayer);

			if (currentPlayer == "X") {
				aMove.emplace_back(x, y);
			}
			else if (currentPlayer == "O") {
				bMove.emplace_back(x, y);
			}

			cout << *this << endl;
			cout << endl;
			cout << "Player " << currentPlayer << ": ";

			const auto& moves = (currentPlayer == "X") ? aMove : bMove;
			for (int i = 0; i < moves.size(); i++) {
				cout << moves[i].first << ", " << moves[i].second;

				if (i != moves.size() - 1) {
					cout << "; ";
				}
			}
			cout << endl;

			//  switch players
			currentPlayer = (currentPlayer == "X") ? "O" : "X";

			return true;
		}
		else {  //  not empty, return invalid action info
			cout << "Invalid Action: the square is already occupied, please try again." << endl;
		}
	}
}

//  print the current board situation, include board and pieces
void TicTacToe::print(ostream& os) const {
	for (int y = 4; y >= 0; y--) {
		os << y << " ";
		for (int x = 0; x < 5; x++) {
			os << setw(maxPieceLength) << board[y][x];
			if (x < 4) {
				os << " ";
			}
		}
		os << endl;
	}
	os << "  ";
	for (int x = 0; x < 5; x++) {
		os << setw(maxPieceLength) << x << " ";
	}
	os << endl;
}

ostream& operator<<(ostream& os, const TicTacToe& game) {
	game.print(os);
	return os;
}