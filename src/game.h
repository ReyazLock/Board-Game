#ifndef GAME_H
#define GAME_H

#include <vector>
#include <ostream>
#include <utility>


class GameBase {
protected:
	std::vector<std::vector<std::string>> board;
	std::string currentPlayer;
	std::vector<std::pair<unsigned int, unsigned int>> xMove;
	std::vector<std::pair<unsigned int, unsigned int>> oMove;

public:
	GameBase();
	virtual ~GameBase() = default;
	virtual bool done() const = 0;
	virtual bool draw() const = 0;
	virtual bool prompt(unsigned int& x, unsigned int& y) = 0;
	virtual bool turn() = 0;
	virtual int play();
	virtual void print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const GameBase& game);
};

#endif