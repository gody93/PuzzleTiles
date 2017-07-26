#ifndef CUBE_H
#define CUBE_H

#include "DrawMgr.h"
#include "Board.h"

class Cube
{
public:
	static Cube* getTile();
	SDL_Surface* getTileSurface();

	void moveDown();
	void handleEvent(SDL_Event&);

	bool checkCollision();

	SDL_Rect getTilePos();

	bool isInsideTile(int,int);

	~Cube();

private:
	Cube();
	static Cube* cube;

	int m_nCubeWidth;
	int m_nCubeHeight;

	int offset;

	SDL_Rect tilePos;

	SDL_Surface* tile;

	SDL_Point mousePos;
	bool isInside;
	bool isSelected;


};

#endif
