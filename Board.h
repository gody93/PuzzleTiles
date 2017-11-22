#ifndef BOARD_H
#define BOARD_H

#include "DrawMgr.h"
#include "Cube.h"
#include "Tile.h"

#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cmath>

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
	void freeTiles();
	void handleEvent(SDL_Event e);
	void printPositions();
	void updatePositions();
	bool isItSolved();
	bool getSuccess();
	void randomize();
	void isThereASolution();
	void endGame();
	~Board();

private:
	Board();
	static Board* board;

	bool success;

	int m_nBoardWidth;
	int m_nBoardHeight;
	int m_nOffset;

	const int tilesCount;

	SDL_Rect boardPos;
	bool hasGameEnded;
	bool hasTileBeenMoved;
	bool hasSolution;

	SDL_Surface* background;

	int r; int g; int b;

	std::vector<Tile*> playBoard;
	std::vector<Tile*> playBoardToModify;
};

#endif
