#ifndef BOARD_H
#define BOARD_H

#include "DrawMgr.h"
#include "Cube.h"
#include "Tile.h"

#include <vector>

class Board : public Cube
{
public:
	static Board* getBoard();

	virtual SDL_Surface* getSurface();
	virtual SDL_Rect& getPos();
	virtual void setPos(int, int);
	virtual int getHeight() const;
	virtual int getWidth() const;


	void fillBoard();
	Tile* getTile();
	void freeTiles();
	void handleEvent(SDL_Event e);
	~Board();



private:
	Board();
	static Board* board;

	int m_nBoardWidth;
	int m_nBoardHeight;

	static const int bRows = 3;
	static const int bCols = 5;

	SDL_Rect boardPos;
	bool firstDraw;

	SDL_Surface* background;

	//std::array< std::array<Tile*,bCols>, bRows> playBoard;
	std::vector<Tile*> playBoard;
	//std::array< std::array<tile, 5>, 3> tiles;
};

#endif
