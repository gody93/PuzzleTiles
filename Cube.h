#ifndef CUBE_H
#define CUBE_H


class Cube
{
public:
	Cube();
	~Cube();
	void Move();
	void OnTouch();
	int GetWidth() { return width; };
	int GetHeight() { return height; };

private:
	int width;
	int height;
};

extern Cube gCube;

#endif
