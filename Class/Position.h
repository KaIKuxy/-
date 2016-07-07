//Position: x, y -> Row, Column

struct Position {
	bool operator == (const Position&);
	Position(int, int);
	Position();
	bool outOfBorder();
	int row , column;
};

struct TetriminoPosition {
	TetriminoPosition();
	TetriminoPosition(Position, Position, Position, Position);
	Position tetrimino[4];
	bool outOfBorder();
};