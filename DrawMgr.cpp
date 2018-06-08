#include "DrawMgr.h"
#include "Menu.h"
#include "Board.h"
#include <iostream>
#include <fstream>


DrawMgr::DrawMgr() : nScreenWidth(500)
				   , nScreenHeight(500)
				   , window(NULL)
				   , screenSurface(NULL)
				   , screenBackground(NULL)
				   , boardBackground(NULL)
				   , endSplash(NULL)
{

}

DrawMgr::~DrawMgr()
{
	delete DrawMgr::mgr;
	DrawMgr::mgr = NULL;

	//Deallocate surface
    SDL_FreeSurface( screenBackground );
    screenBackground = NULL;

	SDL_FreeSurface( screenSurface );
	screenSurface = NULL;

	SDL_FreeSurface( boardBackground );
	boardBackground = NULL;

	SDL_FreeSurface( endSplash );
	endSplash = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

DrawMgr* DrawMgr::getMgr()
{
	if(!mgr)
	{
		mgr = new DrawMgr();
	}
	return mgr;
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

	if( !LoadMedia() )
	{
		std::cout << "Failed to load media!\n";
		return false;
	}
	return true;
}

bool DrawMgr::LoadMedia()
{
    bool success = true;

    if( Menu::getMenu()->getSurface() == NULL )
    {
        printf( "Unable to load menu wallpaper! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }

    screenBackground = SDL_LoadBMP( "img/wallpaper.bmp" );
    if( screenBackground == NULL )
    {
        printf( "Unable to load image wallpaper! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }

	endSplash = SDL_LoadBMP( "img/congratulations.bmp" );
    if( endSplash == NULL )
    {
        printf( "Unable to load image wallpaper! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }

	LoadTileResources();

	boardBackground = Board::getBoard()->getSurface();

	if( boardBackground == NULL)
	{
		printf( "Unable to load board background!" );
		success = false;
	}
    return success;
}

void DrawMgr::DrawMenu()
{
    SDL_BlitScaled( Menu::getMenu()->getSurface(), NULL, screenSurface, NULL);
}

void DrawMgr::UpdateScreen()
{
	SDL_UpdateWindowSurface( window );
}

void DrawMgr::DrawScreenBackground()
{
	SDL_BlitScaled( screenBackground, NULL, screenSurface, NULL );
}

void DrawMgr::DrawBoard()
{
	SDL_BlitSurface( boardBackground , NULL, screenSurface, &(Board::getBoard()->getPos()) );
}

void DrawMgr::DrawButtons(Button* button, SDL_Surface* surface)
{
    SDL_Rect h;
	h.x = button->getPos().x;
	h.y = button->getPos().y;
	h.w = button->getWidth();
	h.h = button->getHeight();
	SDL_BlitSurface( button->getSurface(), &h, surface, &button->getPos() );
}

void DrawMgr::DrawTile(Tile* tile,SDL_Surface* surface)
{
	SDL_Rect h;
	h.x = tile->getPos().x;
	h.y = tile->getPos().y;
	h.w = tile->getWidth();
	h.h = tile->getHeight();
	SDL_BlitSurface( tile->getSurface(), &h, surface, &tile->getPos() );
}

void DrawMgr::LoadTileResources()
{
	std::ifstream stream("img/resources.txt");

	std::string line;
	if( stream.is_open() )
	{
		while(getline( stream, line ) )
		{
			resources.push_back(line);
		}
		stream.close();
	}
}

std::string DrawMgr::GetTileResource(int i)
{
	return resources.at(0);
}

void DrawMgr::DrawEndSplash()
{
	SDL_BlitScaled( endSplash, NULL, screenSurface, NULL );
}

DrawMgr* DrawMgr::mgr = NULL;
