#ifndef TILE_H
#define TILE_H

#include "Cube.h"
#include "Board.h"

class Tile : public Cube
{

public:
	static Tile* getTile();

	virtual SDL_Surface* getSurface();
	SDL_Rect getPos();
	virtual void setPos(int,int);

	void moveDown();
	void handleEvent(SDL_Event&);

	bool checkCollision();

	bool isInsideTile(int,int);

	~Tile();

private:
	Tile();
	static Tile* tile;

	int m_nTileWidth;
	int m_nTileHeight;

	int offset;

	SDL_Rect tilePos;

	SDL_Surface* m_tile;

	SDL_Point mousePos;
	bool isInside;
	bool isSelected;



};

#endif
