//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720
//	1	2	3	4	5	6	7
//	I	J	L	O	S	T	Z

#include "Position.h"

Position::Position(int x, int y) : row(x), column(y) {}

Position::Position() {}

bool Position::operator==(const Position &temp) {
	return temp.row == this->row && temp.column == this->column;
}

Position& Position::operator+(const Position &temp) {
	return Position(this->row + temp.row, this->column + temp.column);
}

TetriminoPosition::TetriminoPosition() {}

TetriminoPosition::TetriminoPosition(Position a, Position b, Position c, Position d) {
	this->tetrimino[0] = a;
	this->tetrimino[1] = b;
	this->tetrimino[2] = c;
	this->tetrimino[3] = d;
}

bool TetriminoPosition::outOfBorder() {	//	True: out of border		False:	not out of border
	bool answer = false;
	for (int i = 0; i < 3; ++i) {
		answer = answer || this->tetrimino[i].outOfBorder();
	}
	return answer;
}

bool Position::outOfBorder() {	//	True: out of border		False:	not out of border
	return (this->row < 0 || this->row > 15 || this->column < 0 || this->column > 9);
}