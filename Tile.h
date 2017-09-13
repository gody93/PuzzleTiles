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
	virtual void setPos(int = 0,int = 0);
	virtual int getWidth() const;
	virtual int getHeight() const;

	SDL_Rect& getTilePos();

	void moveDown();
	void handleEvent(SDL_Event, std::vector<Tile*>&);

	bool checkCollision();

	bool isInsideTile(int,int);

	void setMousePos(int x, int y);

	void setInitalPos(int);

	bool outOfRange();
private:
	int m_nTileWidth;
	int m_nTileHeight;

	int offset;

	SDL_Rect tilePos;

	SDL_Surface* m_tile;

	SDL_Point mousePos;

	bool isInside;
	bool isSelected;

	int initialPos;
	int currPos;



};

#endif
