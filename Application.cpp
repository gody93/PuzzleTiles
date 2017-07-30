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
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				Tile::getTile()->handleEvent(e);
				//User requests quit
				if ( e.type == SDL_QUIT || ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE ) )
				{
					quit = true;
					std::cout << "Game Quits \n";
				}
			}


			DrawMgr::getMgr()->DrawBackground();
			DrawMgr::getMgr()->DrawBoard();
			DrawMgr::getMgr()->UpdateScreen();
		}
	}
}


Application* Application::app = NULL;
