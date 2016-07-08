//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720

#include "Position.h"

class Mino {
public:
	Mino();
	Mino(Position);
	void setPos(Position);
	Position getPos();
	bool samePos(Position);
	bool onRow(int);

private:
	Position pos;
};
