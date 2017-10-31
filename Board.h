#ifndef BOARD_H
#define BOARD_H

#include "DrawMgr.h"
#include "Cube.h"
#include "Tile.h"

#include <vector>
#include <array>

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
	void printPositions();
	void updatePositions();
	bool isItSolved();
	bool getSuccess();
	~Board();

private:
	Board();
	static Board* board;

	int m_nBoardWidth;
	int m_nBoardHeight;
	int m_nOffset;

	static const int tilesCount = 15;

	static const int bRows = 3;
	static const int bCols = 5;

	SDL_Rect boardPos;
	bool firstDraw;
	bool hasTileBeenMoved;
	bool success;

	SDL_Surface* background;

	int r; int g; int b;

	//std::array< std::array<Tile*,bCols>, bRows> playBoard;
	std::vector<Tile*> playBoard;
	std::vector<Tile*> playBoardToModify;
	//std::array< std::array<tile, 5>, 3> tiles;
};

#endif
