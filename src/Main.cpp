/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 04
 * Author: Mingzhi Cai
*/

#include "game.h"
#include "header.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc != expected_argc || string(argv[input_file_name]) != "TicTacToe") {
        return usage(argv[program_name], "TicTacToe");
    }

    try {
        TicTacToe game;
        return game.play();
    }
    catch (...) {
        cerr << "An unexpected error occured." << endl;
        return UNEXPECTED_ERROR;
    }
}