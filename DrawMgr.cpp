#include "DrawMgr.h"

DrawMgr::DrawMgr() : nScreenWidth(500), nScreenHeight(500)
{
}

DrawMgr::~DrawMgr()
{
	Quit();
}

bool DrawMgr::CreateWindow()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	else {
		//Create window
		window = SDL_CreateWindow( "Puzzle Tiles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, nScreenWidth, nScreenHeight, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
		}

	}
	return true;
}

void DrawMgr::DrawBackground()
{
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 55, 100, 173 ) );
}

void DrawMgr::DrawCube()
{
	gCube.Draw(screenSurface);
}

void DrawMgr::Quit()
{
	//Destroy window
	SDL_DestroyWindow( window );
	//Quit SDL subsystems
	SDL_Quit();
}

void DrawMgr::UpdateScreen()
{
	SDL_UpdateWindowSurface( window );
}

DrawMgr gDrawMgr;
