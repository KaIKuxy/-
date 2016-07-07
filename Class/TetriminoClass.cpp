//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720
//	1	2	3	4	5	6	7
//	I	J	L	O	S	T	Z

#include "TetriminoClass.h"

TetriminoPosition iRotate[2] = {
									TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(-2, -2)),
									TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(2, 2))};

TetriminoPosition jRotate[4] = {
									TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(0, -2)),
									TetriminoPosition(Position(-1, 1), Position(0, 0), Position(1, -1), Position(2, 0)),
									TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(0, 2)),
									TetriminoPosition(Position(1, -1), Position(0, 0), Position(-1, 1), Position(-2, 0))};

TetriminoPosition lRotate[4] = {
									TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(2, 0)),
									TetriminoPosition(Position(1, -1), Position(0, 0), Position(-1, 1), Position(0, 2)),
									TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(-2, 0)),
									TetriminoPosition(Position(-1, 1), Position(0, 0), Position(1, -1), Position(0, -2))};

TetriminoPosition sRotate[2] = {
									TetriminoPosition(Position(-1, 0), Position(0, 1), Position(1, 0), Position(2, 1)),
									TetriminoPosition(Position(1, 0), Position(0, -1), Position(-1, 0), Position(-2, -1))};

TetriminoPosition tRotate[4] = {	
									TetriminoPosition(Position(1, -1), Position(1, 1), Position(0, 0), Position(-1, -1)),
									TetriminoPosition(Position(1, 1), Position(-1, 1), Position(0, 0), Position(1, -1)),
									TetriminoPosition(Position(-1, 1), Position(-1, -1), Position(0, 0), Position(1, 1)),
									TetriminoPosition(Position(-1, -1), Position(1, -1), Position(0, 0), Position(-1, 1))};

TetriminoPosition zRotate[2] = {
									TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(0, -2)),
									TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(0, 2))};

Tetrimino::Tetrimino() {}

TetriminoPosition Tetrimino::moveable(int Direction) {	// 0	left	1	right	2	down for one block
	switch (Direction)
	{
	case 0:
		for (int i = 0; i < 4;++i)
			this->moveTo.tetrimino[i] = Position(this->minos[i]->getPos().row, this->minos[i]->getPos().column - 1);
		break;
	case 1:
		for (int i = 0; i < 4;++i)
			this->moveTo.tetrimino[i] = Position(this->minos[i]->getPos().row, this->minos[i]->getPos().column + 1);
		break;
	case 2:
		for (int i = 0; i < 4;++i)
			this->moveTo.tetrimino[i] = Position(this->minos[i]->getPos().row - 1, this->minos[i]->getPos().column);
		break;
	default:
		break;
	}
	return this->moveTo;
}

void Tetrimino::move() {	// 0	left	1	right	2	down for one block
	for (int i = 0; i < 4; ++i) {
		this->minos[i]->setPos(this->moveTo.tetrimino[i]);
	}
}

bool Tetrimino::outOfBorder() {
	return this->moveTo.outOfBorder();
}

Tetris_I::Tetris_I(int Type) {
	this->type = Type;
	switch (this->type)
	{
	case 0:
		minos[0] = new Mino(Position(15, 3));
		minos[1] = new Mino(Position(15, 4));
		minos[2] = new Mino(Position(15, 5));
		minos[3] = new Mino(Position(15, 6));
		break;
	case 1:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(14, 5));
		minos[2] = new Mino(Position(13, 5));
		minos[3] = new Mino(Position(12, 5));
		break;
	default:
		break;
	}
}

Tetris_J::Tetris_J(int Type) {
	this->type = Type;
	switch (this->type)
	{
	case 0:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(15, 5));
		minos[2] = new Mino(Position(15, 6));
		minos[3] = new Mino(Position(14, 6));
		break;
	case 1:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(14, 5));
		minos[2] = new Mino(Position(13, 5));
		minos[3] = new Mino(Position(13, 4));
		break;
	case 2:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(14, 4));
		minos[2] = new Mino(Position(14, 5));
		minos[3] = new Mino(Position(14, 6));
		break;
	case 3:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(15, 4));
		minos[2] = new Mino(Position(14, 4));
		minos[3] = new Mino(Position(13, 4));
		break;
	default:
		break;
	}
}

Tetris_L::Tetris_L(int Type) {
	this->type = Type;
	switch (this->type)
	{
	case 0:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(15, 5));
		minos[2] = new Mino(Position(15, 6));
		minos[3] = new Mino(Position(14, 4));
		break;
	case 1:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(15, 5));
		minos[2] = new Mino(Position(14, 5));
		minos[3] = new Mino(Position(13, 5));
		break;
	case 2:
		minos[0] = new Mino(Position(15, 6));
		minos[1] = new Mino(Position(14, 4));
		minos[2] = new Mino(Position(14, 5));
		minos[3] = new Mino(Position(14, 6));
		break;
	case 3:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(14, 4));
		minos[2] = new Mino(Position(13, 4));
		minos[3] = new Mino(Position(13, 5));
		break;
	default:
		break;
	}
}

Tetris_O::Tetris_O() {
	this->type = 0;
	minos[0] = new Mino(Position(15, 4));
	minos[1] = new Mino(Position(15, 5));
	minos[2] = new Mino(Position(14, 4));
	minos[3] = new Mino(Position(14, 5));
}

Tetris_S::Tetris_S(int Type) {
	this->type = Type;
	switch (this->type)
	{
	case 0:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(15, 6));
		minos[2] = new Mino(Position(14, 4));
		minos[3] = new Mino(Position(14, 5));
		break;
	case 1:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(14, 4));
		minos[2] = new Mino(Position(14, 5));
		minos[3] = new Mino(Position(13, 5));
		break;
	default:
		break;
	}
}

Tetris_T::Tetris_T(int Type) {
	this->type = Type;
	switch (this->type)
	{
	case 0:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(15, 5));
		minos[2] = new Mino(Position(15, 6));
		minos[3] = new Mino(Position(14, 5));
		break;
	case 1:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(14, 5));
		minos[2] = new Mino(Position(13, 5));
		minos[3] = new Mino(Position(14, 4));
		break;
	case 2:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(14, 4));
		minos[2] = new Mino(Position(14, 5));
		minos[3] = new Mino(Position(14, 6));
		break;
	case 3:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(14, 5));
		minos[2] = new Mino(Position(13, 5));
		minos[3] = new Mino(Position(14, 6));
		break;
	default:
		break;
	}
}

Tetris_Z::Tetris_Z(int Type) {
	this->type = Type;
	switch (this->type)
	{
	case 0:
		minos[0] = new Mino(Position(15, 4));
		minos[1] = new Mino(Position(15, 5));
		minos[2] = new Mino(Position(14, 5));
		minos[3] = new Mino(Position(15, 6));
		break;
	case 1:
		minos[0] = new Mino(Position(15, 5));
		minos[1] = new Mino(Position(14, 5));
		minos[2] = new Mino(Position(14, 4));
		minos[3] = new Mino(Position(13, 4));
		break;
	default:
		break;
	}
}

TetriminoPosition Tetris_I::rotatable() {
	this->moveTo
}

TetriminoPosition Tetris_J::rotatable() {

}

TetriminoPosition Tetris_L::rotatable() {

}

TetriminoPosition Tetris_O::rotatable() {
	for (int i = 0; i < 4; ++i) {
		this->moveTo.tetrimino[i].row = this->minos[i]->getPos().row;
		this->moveTo.tetrimino[i].column = this->minos[i]->getPos().column;
	}
	return this->moveTo;
}

TetriminoPosition Tetris_S::rotatable() {

}

TetriminoPosition Tetris_T::rotatable() {

}

TetriminoPosition Tetris_Z::rotatable() {

}
