#include "DrawMgr.h"

DrawMgr::DrawMgr() : nScreenWidth(500), nScreenHeight(500)
{

}

DrawMgr::~DrawMgr()
{
	delete DrawMgr::mgr;
	DrawMgr::mgr = NULL;


	//Deallocate surface
    SDL_FreeSurface( background );
    background = NULL;

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
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, nScreenWidth, nScreenHeight, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return false;
        }
        else
        {
            //Get window surface
            screenBackground = SDL_GetWindowSurface( window );
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
    background = SDL_LoadBMP( "img/wallpaper.bmp" );
    if( background == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "img", SDL_GetError() );
        success = false;
    }

    return success;
}

void DrawMgr::UpdateScreen()
{
	SDL_UpdateWindowSurface( window );
}

void DrawMgr::DrawBackground()
{
	SDL_BlitScaled( background, NULL, screenBackground, NULL );
}

DrawMgr* DrawMgr::mgr = NULL;
