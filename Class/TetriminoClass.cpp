//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720
//	1	2	3	4	5	6	7
//	I	J	L	O	S	T	Z

#include "TetriminoClass.h"

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

TetriminoPosition Tetrimino::rotatable() {
	for (int i = 0; i < 4; ++i)
		this->moveTo.tetrimino[i] = this->minos[i]->getPos() + this->Rotate[this->type].tetrimino[i];
	this->type = (this->type + 1) % this->totalType;
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
	this->totalType = 2;
	this->type = Type;
	this->Rotate[0] = TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(-2, -2));
	this->Rotate[1] = TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(2, 2));
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
	this->totalType = 4;
	this->type = Type;
	this->Rotate[0] = TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(0, -2));
	this->Rotate[1] = TetriminoPosition(Position(-1, 1), Position(0, 0), Position(1, -1), Position(2, 0));
	this->Rotate[2] = TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(0, 2));
	this->Rotate[3] = TetriminoPosition(Position(1, -1), Position(0, 0), Position(-1, 1), Position(-2, 0));
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
	this->totalType = 4;
	this->type = Type;
	this->Rotate[0] = TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(2, 0));
	this->Rotate[1] = TetriminoPosition(Position(1, -1), Position(0, 0), Position(-1, 1), Position(0, 2));
	this->Rotate[2] = TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(-2, 0));
	this->Rotate[3] = TetriminoPosition(Position(-1, 1), Position(0, 0), Position(1, -1), Position(0, -2));
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
	this->totalType = 1;
	this->type = 0;
	minos[0] = new Mino(Position(15, 4));
	minos[1] = new Mino(Position(15, 5));
	minos[2] = new Mino(Position(14, 4));
	minos[3] = new Mino(Position(14, 5));
}

Tetris_S::Tetris_S(int Type) {
	this->totalType = 2;
	this->type = Type;
	this->Rotate[0] = TetriminoPosition(Position(-1, 0), Position(0, 1), Position(1, 0), Position(2, 1));
	this->Rotate[1] = TetriminoPosition(Position(1, 0), Position(0, -1), Position(-1, 0), Position(-2, -1));
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
	this->totalType = 4;
	this->type = Type;
	this->Rotate[0] = TetriminoPosition(Position(1, -1), Position(1, 1), Position(0, 0), Position(-1, -1));
	this->Rotate[1] = TetriminoPosition(Position(1, 1), Position(-1, 1), Position(0, 0), Position(1, -1));
	this->Rotate[2] = TetriminoPosition(Position(-1, 1), Position(-1, -1), Position(0, 0), Position(1, 1));
	this->Rotate[3] = TetriminoPosition(Position(-1, -1), Position(1, -1), Position(0, 0), Position(-1, 1));
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
	this->totalType = 2;
	this->type = Type;
	this->Rotate[0] = TetriminoPosition(Position(1, 1), Position(0, 0), Position(-1, -1), Position(0, -2));
	this->Rotate[1] = TetriminoPosition(Position(-1, -1), Position(0, 0), Position(1, 1), Position(0, 2));
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

TetriminoPosition Tetris_O::rotatable() {
	for (int i = 0; i < 4; ++i) {
		this->moveTo.tetrimino[i].row = this->minos[i]->getPos().row;
		this->moveTo.tetrimino[i].column = this->minos[i]->getPos().column;
	}
	return this->moveTo;
}
