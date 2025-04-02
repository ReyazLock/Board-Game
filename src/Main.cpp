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

using namespace std;


int main(int argc, char* argv[]) {
    GameBase* game = GameBase::checkArgs(argc, argv);
    if (!game) {
        return usage(argv[program_name], "TicTacToe");
    }

    try {
        int result = game->play();
        delete game;
        return result;
    }
    catch (...) {
        delete game;
        cout << "An unexpected error occuted." << endl;
        return UNEXPECTED_ERROR;
    }
}