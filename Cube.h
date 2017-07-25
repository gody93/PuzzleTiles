#ifndef CUBE_H
#define CUBE_H
#include "DrawMgr.h"

class Cube
{
public:
	static Cube* getCube();
	SDL_Surface* DrawCube();
	SDL_Surface* DrawBoard();

	void moveDown();
	void handleEvent(SDL_Event&);

	bool checkCollision();

	void setBoardPos(int,int);
	SDL_Rect getBoardPos();

	SDL_Rect getTilePos();

	~Cube();

private:
	Cube();
	static Cube* cube;

	int m_nCubeWidth;
	int m_nCubeHeight;

	int m_nBoardWidth;
	int m_nBoardHeight;

	int offset;

	SDL_Rect boardPos;
	SDL_Rect tilePos;

	SDL_Surface* tile;
	SDL_Surface* boardBackground;

	SDL_Point mousePos;
	bool isInside;
	bool isSelected;


};

#endif
