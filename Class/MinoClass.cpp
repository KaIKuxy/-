//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720

#include "MinoClass.h"

Mino::Mino() {}

Mino::Mino(Position pos) {
	this->pos = pos;
}

void Mino::setPos(Position setPos) {
	this->pos = setPos;
}

Position Mino::getPos() {
	return this->pos;
}

bool Mino::samePos(Position tryPos) {
	return tryPos == this->pos;
}