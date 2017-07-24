#ifndef CUBE_H
#define CUBE_H
#include "DrawMgr.h"

class Cube
{
public:
	static Cube* getCube();
	SDL_Surface* DrawCube();
	SDL_Surface* DrawBoard();

	void setBoardPos(int,int);

	SDL_Rect getBoardPos();
	~Cube();

private:
	Cube();
	static Cube* cube;

	int m_nCubeWidth;
	int m_nCubeHeight;

	int m_nBoardWidth;
	int m_nBoardHeight;

	SDL_Rect boardPos;

	SDL_Surface* tile;
	SDL_Surface* boardBackground;


};

#endif
