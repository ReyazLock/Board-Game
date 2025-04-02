#ifndef GOMOKU_H
#define GOMOKU_H

#include "game.h"


class Gomoku : public GameBase {
public:
	Gomoku();
	virtual bool done() const override;
	virtual bool draw() const override;
	virtual bool prompt(unsigned int& x, unsigned int& y) override;
	virtual bool turn() override;
	virtual void print(std::ostream& os) const override;
};

#endif