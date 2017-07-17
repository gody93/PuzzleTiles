#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
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
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
		}
	}
}

Application* Application::app = NULL;
