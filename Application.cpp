#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
	delete Application::app;
	Application::app = NULL;
}


Application* Application::getApp()
{
	if(!app)
	{
		app = new Application();
	}
	return app;
}



void Application::Start()
{
	SDL_Event e;
	bool quit = false;
	//Start up SDL and create window
	if (!DrawMgr::getMgr()->CreateWindow())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		while (!quit)
		{

			DrawMgr::getMgr()->DrawScreenBackground();

			DrawMgr::getMgr()->DrawBoard();

			DrawMgr::getMgr()->UpdateScreen();
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				Board::getBoard()->handleEvent(e);
				//User requests quit
				if ( e.type == SDL_QUIT || ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE ) )
				{
					quit = true;
					std::cout << "Game Quits \n";
				}
				else if( ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p ) )
				{
					Board::getBoard()->printPositions();
				}
				else if( ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_r ) )
				{
					Board::getBoard()->randomize();
				}
			}
			if( Board::getBoard()->getSuccess() )
			{
				std::cout << " Congratulations ! \n";
			}
		}
	}
}


Application* Application::app = NULL;
