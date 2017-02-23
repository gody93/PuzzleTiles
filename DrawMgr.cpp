#include "DrawMgr.h"

DrawMgr::DrawMgr() : nScreenWidth(500), nScreenHeight(500), screenBackground(NULL)
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
	else
	{
		SDL_CreateWindowAndRenderer(nScreenWidth, nScreenHeight, SDL_WINDOW_RESIZABLE, &window, &renderer);
		if( (window == NULL) || (renderer == NULL) )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
	}
	return true;
}

void DrawMgr::DrawBackground()
{
	//SDL_SetRenderDrawColor(renderer, 100, 10, 0, 255);
	screenBackground = SDL_CreateRGBSurface(0, nScreenWidth, nScreenHeight, 32, 0, 0, 0, 0);

	SDL_FillRect(screenBackground, NULL, SDL_MapRGB(screenBackground->format, 120, 100, 10) );

	if(screenBackground == NULL)
	{
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
	}


	backgroundTexture = SDL_CreateTextureFromSurface(renderer, screenBackground);

	SDL_FreeSurface(screenBackground);

	SDL_RenderCopy(renderer,backgroundTexture, NULL, NULL);

}

void DrawMgr::DrawCube()
{
	gCube.Draw(*renderer);
}

void DrawMgr::Quit()
{
	// //Destroy window
	SDL_DestroyWindow( window );

	SDL_DestroyRenderer(renderer);

	//Quit SDL subsystems
	SDL_Quit();
}

void DrawMgr::ClearScreen()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void DrawMgr::UpdateScreen()
{
	SDL_RenderPresent(renderer);
}

DrawMgr gDrawMgr;
