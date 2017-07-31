#ifndef BOARD_H
#define BOARD_H

#include "DrawMgr.h"
#include "Cube.h"
#include "Tile.h"

#include <array>

class Board : public Cube
{
public:
	static Board* getBoard();
	virtual SDL_Surface* getSurface();
	virtual SDL_Rect* getPos();
	virtual void setPos(int, int);

	void fillBoard();

	virtual int getHeight() const;
	virtual int getWidth() const;

	~Board();



private:
	Board();
	static Board* board;

	int m_nBoardWidth;
	int m_nBoardHeight;

	static const int bRows = 3;
	static const int bCols = 5;

	SDL_Rect boardPos;

	SDL_Surface* boardBackground;

	std::array< std::array<int,bCols>, bRows> playBoard;
	//std::array< std::array<tile, 5>, 3> tiles;
	// void fillBoard();
};

#endif
