#ifndef BOARD_H
#define BOARD_H

#include "DrawMgr.h"
#include "Cube.h"

class Board : public Cube
{
public:
	static Board* getBoard();
	virtual SDL_Surface* getSurface();
	~Board();



private:
	Board();
	static Board* board;

	int m_nBoardWidth;
	int m_nBoardHeight;

	SDL_Rect boardPos;

	SDL_Surface* boardBackground;

	// void fillBoard();
	// SDL_Rect getBoardPos();
};

#endif
