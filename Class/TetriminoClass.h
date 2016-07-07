//A Tetrimino contains four Minos
//Row: 16   Column: 10
//From left: 0 -> 9   From down: 0 -> 15
//1280*720

#include "MinoClass.h"

class Tetrimino{
public:
	Tetrimino();
	TetriminoPosition moveable(int);	// 0	left	1	right	2	down for one block
	virtual TetriminoPosition rotatable() = 0;
	void move();
	bool outOfBorder();	//	know if the next move or rotate is going to be out of border
private:

protected:
	Mino *minos[4];
	int type;
	TetriminoPosition moveTo;
};

class Tetris_I : public Tetrimino {	// type: 0	1
public:
	Tetris_I(int);
	TetriminoPosition rotatable();
};

class Tetris_J : public Tetrimino {	// type: 0	1	2	3
public:
	Tetris_J(int);
	TetriminoPosition rotatable();
};

class Tetris_L : public Tetrimino {	// type: 0	1	2	3
public:
	Tetris_L(int);
	TetriminoPosition rotatable();
};

class Tetris_O : public Tetrimino {	// type: 0
public:
	Tetris_O();
	TetriminoPosition rotatable();
};

class Tetris_S : public Tetrimino {	// type: 0	1
public:
	Tetris_S(int);
	TetriminoPosition rotatable();
};

class Tetris_T : public Tetrimino {	// type: 0	1	2	3
public:
	Tetris_T(int);
	TetriminoPosition rotatable();
};

class Tetris_Z : public Tetrimino {	// type: 0	1
public:
	Tetris_Z(int);
	TetriminoPosition rotatable();
};
