//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720

//#include "Position.h"
#include <cocos2d.h>
using namespace cocos2d;

class Mino {
public:
	Mino();
	Mino(Vec2);
	void setPos(Vec2);
	Vec2 getPos();
	bool samePos(Vec2);
	bool onRow(int);

private:
	Vec2 pos;
};
