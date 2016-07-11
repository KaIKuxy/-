//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720

#include "MinoClass.h"

Mino::Mino() {}

Mino::Mino(Vec2 pos) {
	this->pos = pos;
}

void Mino::setPos(Vec2 setPos) {
	this->pos = setPos;
}

Vec2 Mino::getPos() {
	return this->pos;
}

bool Mino::samePos(Vec2 tryPos) {
	return tryPos == this->pos;
}

bool Mino::onRow(int row) {
	return this->pos.x == row;
}