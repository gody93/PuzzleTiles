#ifndef BOARD_H
#define BOARD_H
#include "Cube.h"

class Board
{
public:
	Board();
	~Board();
private:
	Cube gameBoard[3][3];

};

#endif
