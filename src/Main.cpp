/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 04
 * Author: Mingzhi Cai
*/

#include "game.h"
#include "header.h"
#include "TicTacToe.h"
#include <iostream>
#include <memory>

using namespace std;


int main(int argc, char* argv[]) {
	try {
		shared_ptr<GameBase> game(GameBase::checkArgs(argc, argv));

		if (!game) {
			return usage(argv[program_name], "TicTacToe");
		}

		int result = game->play();
		return result;
	}
	catch (const bad_alloc&) {
		cout << "Error: Failed to allocate memory for the game." << endl;
		return MEMORY_BAD_ALLOC_ERROR;
	}
	catch (...) {
		cout << "An unexpected error occured." << endl;
		return UNEXPECTED_ERROR;
	}
}