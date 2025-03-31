#ifndef GAME_H
#define GAME_H

#include <vector>
#include <ostream>


class TicTacToe {
private:
	char board[5][5];
	char currentPlayer;
	std::vector<std::pair<unsigned int, unsigned int>> xMove;
	std::vector<std::pair<unsigned int, unsigned int>> oMove;

	friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);
public:
	TicTacToe();
	bool done() const;
	bool draw() const;
	bool prompt(unsigned int& x, unsigned int& y);
	bool turn();
	int play();
};

#endif