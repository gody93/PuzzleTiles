#include "Application.h"

Application::Application()
{
}

Application::~Application()
{

}

void Application::Start()
{
	SDL_Event e;
	bool quit = false;
	//Start up SDL and create window
	if (!gDrawMgr.CreateWindow())
	{
		printf("Failed to initialize!\n");
	}

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}
		//Draw Background

		//UpdateScreen
		gDrawMgr.UpdateScreen();
	}
}

Application gApp;
