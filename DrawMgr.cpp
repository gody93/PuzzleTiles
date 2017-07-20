#include "DrawMgr.h"

DrawMgr::DrawMgr() : nScreenWidth(500), nScreenHeight(500)
{

}

DrawMgr::~DrawMgr()
{
	delete DrawMgr::mgr;
	DrawMgr::mgr = NULL;


	 //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

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
    gHelloWorld = SDL_LoadBMP( "img/wallpaper.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
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
	SDL_BlitScaled( gHelloWorld, NULL, screenBackground, NULL );
}

void DrawMgr::DrawCube()
{
	SDL_Surface* cube;

	/* Creating the surface. */
	cube = SDL_CreateRGBSurface(0, 50, 50, 32, 0, 0, 0, 0);

	/* Filling the surface with red color. */
	SDL_FillRect(cube, NULL, SDL_MapRGB(cube->format, 255, 0, 0));

	SDL_BlitSurface( cube, NULL, screenBackground, NULL);

}
DrawMgr* DrawMgr::mgr = NULL;
















// void DrawMgr::DrawBackground()
// {
// 	//SDL_SetRenderDrawColor(renderer, 100, 10, 0, 255);
// 	screenBackground = SDL_CreateRGBSurface(0, nScreenWidth, nScreenHeight, 32, 0, 0, 0, 0);

// 	SDL_FillRect(screenBackground, NULL, SDL_MapRGB(screenBackground->format, 120, 100, 10) );

// 	if(screenBackground == NULL)
// 	{
// 		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
// 	}


// 	backgroundTexture = SDL_CreateTextureFromSurface(renderer, screenBackground);

// 	SDL_FreeSurface(screenBackground);

// 	SDL_RenderCopy(renderer,backgroundTexture, NULL, NULL);

// }

// void DrawMgr::DrawCube()
// {
// 	gCube.Draw(*renderer);
// }

// void DrawMgr::Quit()
// {
// }

// void DrawMgr::ClearScreen()
// {
// 	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
// 	SDL_RenderClear(renderer);
// }

// void DrawMgr::UpdateScreen()
// {
// 	SDL_RenderPresent(renderer);
// }
