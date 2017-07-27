#ifndef TILE_H
#define TILE_H

class Tile
{

public:
	static Tile* getTile();
	SDL_Surface* getTileSurface();

	void moveDown();
	void handleEvent(SDL_Event&);

	bool checkCollision();

	SDL_Rect getTilePos();

	bool isInsideTile(int,int);

	~Tile();

private:
	Tile();
	static Tile* tile;

	int m_nTileWidth;
	int m_nTileHeight;

	int offset;

	SDL_Rect tilePos;

	SDL_Surface* tile;

	SDL_Point mousePos;
	bool isInside;
	bool isSelected;



};

#endif
