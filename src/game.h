#ifndef GAME_H
#define GAME_H

#include <vector>
#include <ostream>
#include <utility>


class GameBase {
protected:
	std::vector<std::vector<std::string>> board;
	std::string currentPlayer;
	std::vector<std::pair<unsigned int, unsigned int>> aMove;
	std::vector<std::pair<unsigned int, unsigned int>> bMove;
	size_t maxPieceLength;

	void setPiece(unsigned int x, unsigned int y, const std::string& piece) {
		board[y][x] = piece;
		if (piece.length() > maxPieceLength) {
			maxPieceLength = piece.length();
		}
	}

public:
	GameBase(size_t width, size_t height, const std::string& player);
	virtual ~GameBase() = default;
	virtual bool done() const = 0;
	virtual bool draw() const = 0;
	virtual bool prompt(unsigned int& x, unsigned int& y) = 0;
	virtual bool turn() = 0;
	virtual int play();
	virtual void print(std::ostream& os) const = 0;
	static GameBase* checkArgs(int argc, char* argv[]);

	friend std::ostream& operator<<(std::ostream& os, const GameBase& game);
};

#endif