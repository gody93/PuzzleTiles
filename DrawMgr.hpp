#include <SDL2/SDL.h>
class DrawMgr
{
public:
	DrawMgr();
	~DrawMgr();
	void CreateWindow();
	void DrawBackground(int,int);
	void Quit();


private:

	SDL_Window* window;
	SDL_Surface* screenSurface;
};
