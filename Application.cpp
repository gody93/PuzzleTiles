#include "Application.h"

Application::Application() : pressStart(false)
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
            if(!pressStart)
            {
                DrawMgr::getMgr()->DrawMenu();
            }
			else if( !Board::getBoard()->getSuccess() )
			{
				DrawMgr::getMgr()->DrawScreenBackground();

				DrawMgr::getMgr()->DrawBoard();
			}
			else
			{
				DrawMgr::getMgr()->DrawEndSplash();
			}

			DrawMgr::getMgr()->UpdateScreen();
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				if( !Board::getBoard()->getSuccess() )
				{
					Board::getBoard()->handleEvent(e);
				}
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
				else if( ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s ) )
				{
                    pressStart = true;
					Board::getBoard()->startGame();
				}
			}
		}
	}
}


Application* Application::app = NULL;
