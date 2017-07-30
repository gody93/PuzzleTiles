#ifndef BOARD_H
#define BOARD_H

#include "DrawMgr.h"
#include "Cube.h"
#include "Tile.h"

class Board : public Cube
{
public:
	static Board* getBoard();
	virtual SDL_Surface* getSurface();
	virtual SDL_Rect getPos();
	virtual void setPos(int, int);

	int getBoardHeight() const;
	int getBoardWidth() const;

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
