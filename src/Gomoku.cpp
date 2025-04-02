#include "header.h"
#include "game.h"
#include "Gomoku.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


Gomoku::Gomoku() : GameBase(20, 20, "B") {}

bool Gomoku::done() const {
	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 19; x++) {
			if (board[y][x] == " ") {
				continue;
			}
			string stone = board[y][x];

			//  Horizontal
			if (x <= 14 && board[y][x + 1] == stone && board[y][x + 2] == stone && board[y][x + 3] == stone && board[y][x + 4] == stone) {
				return true;
			}

			//  Vertical
			if (x <= 14 && board[y+1][x] == stone && board[y+2][x] == stone && board[y+3][x] == stone && board[y+4][x] == stone) {
				return true;
			}

			//  Diagonal down-right
			if (x <= 14 && y <= 14 && board[y + 1][x + 1] == stone && board[y + 2][x + 2] == stone && board[y + 3][x + 3] == stone && board[y + 4][x + 4] == stone) {
				return true;
			}

			//  Diagonal down-left
			if (x >= 4 && y <= 14 && board[y + 1][x - 1] == stone && board[y + 2][x - 2] == stone && board[y + 3][x - 3] == stone && board[y + 4][x - 4] == stone) {
				return true;
			}
		}
	}
	return false;
}

bool Gomoku::draw() const {
	if (done()) {
		return false;
	}

	for (const auto& row : board) {
		for (const auto& cell : row) {
			if (cell == " ") {
				return false;
			}
		}
	}
	return true;
}

bool Gomoku::prompt(unsigned int& x, unsigned int& y) {
	string input;

	while (true) {
		cout << "Enter 'quit' or coordinates(x, y) between 1 ~ 19: ";
		getline(cin, input);
		
		if (input == "quit") {
			return false;
		}

		replace(input.begin(), input.end(), ',', ' ');
		istringstream iss(input);

		if (iss >> x >> y) {
			char remain;

			if (iss >> remain) {
				cout << "Invalid input : extra characters after coorinates." << endl;
			}
			else {
				if (x >= 1 && x <= 19 && y >= 1 && y <= 19) {
					x--;
					y--;
					return true;
				}
				else {
					cout << "Coordinates must be between 1 and 19, please try again." << endl;
				}
			}
		}
		else {
			cout << "Invalid input. Please enter coordinates as x, y or 'quit'." << endl;
		}
	}
}

bool Gomoku::turn() {
	cout << "Player " << currentPlayer << "'s turn." << endl;

	while (true) {
		unsigned int x, y;
		bool continueGame = prompt(x, y);

		if (!continueGame) {
			return false;
		}

		if (board[y][x] == " ") {
			setPiece(x, y, currentPlayer);

			if (currentPlayer == "B") {
				aMove.emplace_back(x, y);
			}
			else if (currentPlayer == "W") {
				bMove.emplace_back(x, y);
			}

			cout << *this << endl;
			cout << endl;
			cout << "Player " << currentPlayer << ": ";

			const auto& moves = (currentPlayer == "B") ? aMove : bMove;
			for (size_t i = 0; i < moves.size(); i++) {
				cout << moves[i].first + 1 << "," << moves[i].second + 1;

				if (i != moves.size() - 1) {
					cout << "; ";
				}
			}
			cout << endl;
			currentPlayer = (currentPlayer == "B") ? "W" : "B";

			return true;
		}
		else {
			cout << "Invalid Action: the square is already occupied, please try again." << endl;
		}
	}
}

void Gomoku::print(ostream& os) const {
	for (int y = 18; y >= 0; y--) {
		if (y >= 9) { //这里应该这么判断
			os << " " << y + 1 << " ";
		}
		else {
			os << "  " << y + 1 << " ";
		}

		for (int x = 0; x < 19; x++) {
			os << setw(maxPieceLength) << board[y][x];
			if (x < 18) {
				os << " ";
			}
		}
		os << endl;
	}
	os << "    ";
	for (int x = 0; x < 19; x++) {
		if (x < 9) {
			os << x + 1 << " ";
		}
		else {
			os << x + 1;
			if (x < 18) {
				os << " ";
			}
		}
	}
	os << endl;
}

ostream& operator<<(ostream& os, const Gomoku& game) {
	game.print(os);
	return os;
}