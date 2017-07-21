#ifndef CUBE_H
#define CUBE_H
#include "DrawMgr.h"

class Cube
{
public:
	static Cube* getCube();
	~Cube();

private:
	Cube();
	static Cube* cube;

	int m_nCubeWidth;
	int m_nCubeHeight;

};

#endif
