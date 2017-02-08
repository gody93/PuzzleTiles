#include <iostream>
#include "DrawMgr.h"
#include <SDL2/SDL.h>

int main()
{

	SDL_Event e;
	bool quit = false;


	while( !quit)
	{
		gDrawMgr.CreateWindow();
		while (SDL_PollEvent(&e) != 0)
		{
			if( e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

		if(currentKeyStates[ SDL_SCANCODE_UP])
		{
			std::cout << "Key event\n\n\n";
		}
	}

	return 0;
}
