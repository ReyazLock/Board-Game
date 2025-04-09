#ifndef GAME_H
#define GAME_H

#include <vector>
#include <ostream>
#include <utility>


//  Refactor game class header file
class GameBase {  
protected:
	std::vector<std::vector<std::string>> board;	//  vector contain playbord
	std::string currentPlayer;	//  current player (XO for tictactoe, WB for gomoku)
	std::vector<std::pair<unsigned int, unsigned int>> aMove;	//  piece move
	std::vector<std::pair<unsigned int, unsigned int>> bMove;	//  piece move
	size_t maxPieceLength;	//  using for control the piece's length

	//  set the piece into the board
	void setPiece(unsigned int x, unsigned int y, const std::string& piece) {
		board[y][x] = piece;
		if (piece.length() > maxPieceLength) {
			maxPieceLength = piece.length();
		}
	}

	//  public contain the base functions for two board playing
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