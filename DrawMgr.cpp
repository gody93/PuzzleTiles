#include "DrawMgr.h"

DrawMgr::DrawMgr()
{}

DrawMgr::~DrawMgr()
{
	Quit();
}

void DrawMgr::CreateWindow()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else {
		//Create window
		window = SDL_CreateWindow( "Puzzle Tiles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			//Update the surface
			SDL_UpdateWindowSurface( window );
			//Wait two seconds
			SDL_Delay( 2000 ); }
	}

}

void DrawMgr::DrawBackground(int width, int heigh)
{

}

void DrawMgr::DrawCube()
{
	SDL_Rect rect;
	rect.w = gCube.GetWidth();
}

void DrawMgr::Quit()
{
	//Destroy window
	SDL_DestroyWindow( window );
	//Quit SDL subsystems
	SDL_Quit();
}

DrawMgr gDrawMgr;
