#ifndef TILE_H
#define TILE_H

#include <iostream>
#include "Cube.h"

class Tile : public Cube
{

public:
	Tile();
	~Tile();
	virtual SDL_Surface* getSurface();
	virtual SDL_Rect getPos();
	virtual void setPos(int,int);
	virtual int getWidth() const;
	virtual int getHeight() const;

	void moveDown();
	void handleEvent(SDL_Event);

	bool checkCollision();

	bool isInsideTile(int,int);




private:
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
