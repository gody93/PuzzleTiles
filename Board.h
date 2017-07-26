#ifndef BOARD_H
#define BOARD_H

#include "DrawMgr.h"
#include "Cube.h"

class Board
{
public:
	static Board* getBoard();
	~Board();

	SDL_Surface* getBoardSurface();
	void fillBoard();
	SDL_Rect getBoardPos();

private:
	Board();
	static Board* board;

	int m_nBoardWidth;
	int m_nBoardHeight;

	SDL_Rect boardPos;

	SDL_Surface* boardBackground;
};

#endif
