#include "DrawMgr.h"

DrawMgr::DrawMgr() : nScreenWidth(500), nScreenHeight(500), window(NULL), screenSurface(NULL), screenBackground(NULL), boardBackground(NULL), tileMarker(NULL)
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

	SDL_FreeSurface( tileMarker );
	tileMarker= NULL;

	SDL_FreeSurface( boardBackground );
	boardBackground = NULL;

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

	if( !loadMedia() )
	{
		std::cout << "Failed to load media!\n";
		return false;
	}
	return true;
}

bool DrawMgr::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    screenBackground = SDL_LoadBMP( "img/wallpaper.bmp" );
    if( screenBackground == NULL )
    {
        printf( "Unable to load image wallpaper! SDL Error: %s\n", "img", SDL_GetError() );
        success = false;
    }

	// tileMarker = SDL_LoadBMP( "img/marker.bmp");
	// if( tileMarker == NULL )
    // {
    //     printf( "Unable to load image marker! SDL Error: %s\n", "img", SDL_GetError() );
    //     success = false;
    // }

	boardBackground = Board::getBoard()->getSurface();
	if( boardBackground == NULL)
	{
		printf( "Unable to load board background!" );
		success = false;
	}


    return success;
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
	SDL_Rect temp = Board::getBoard()->getPos();

	SDL_BlitSurface( boardBackground , NULL, screenSurface, &temp );
}

SDL_Surface* DrawMgr::getMarker()
{
	return tileMarker;
}

SDL_Surface* DrawMgr::getScreenSurface()
{
	return screenSurface;
}

DrawMgr* DrawMgr::mgr = NULL;
