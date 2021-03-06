#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Cube.h"

class Tile : public Cube
{

public:
	Tile();
	~Tile();
	virtual SDL_Surface* getSurface();
	virtual SDL_Rect& getPos();
	virtual void setPos(int = 0, int = 0);
	virtual int getWidth() const;
	virtual int getHeight() const;

	SDL_Rect& getTilePos();

	void setColour( int red, int green, int blue );

	void moveDown();
	void moveUp();
	void moveRight();
	void moveLeft();

	bool isInsideTile(int,int);

	void setMousePos(int x, int y);

	void setInitialPos(int);
	int getInitialPos() const;

	int getCurrPos() const;
	void setCurrPos(int);

	bool isInCorrectPlace();
	void setSurface(std::string);

private:
	int m_nTileWidth;
	int m_nTileHeight;

	int offset;

	SDL_Rect tilePos;

	SDL_Surface* m_tile;

	SDL_Point mousePos;

	bool isInside;

	int initialPos;
	int currPos;

	int r;
	int g;
	int b;

	int x;
	int y;
};

#endif
