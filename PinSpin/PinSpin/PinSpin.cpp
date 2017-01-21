// PinSpin.cpp : Application made during Spartahack 2017
//

#include "stdafx.h"
#include <iostream>
#include <include/SDL.h>   
#include <include/SDL_image.h>  

using namespace std;

int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_Window * window = SDL_CreateWindow("Application",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 480, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = IMG_Load("../../images/pin_design_outline.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_KP_1:
						break;
					case SDLK_KP_2:
						break;
					case SDLK_KP_3:
						break;
					case SDLK_KP_4:
						break;
					case SDLK_KP_5:
						break;
					case SDLK_KP_6:
						break;
					case SDLK_KP_7:
						break;
					case SDLK_KP_8:
						break;
					case SDLK_KP_9:
						break;
					default:
						cout << "Unmapped key press." << endl;
						break;
				}
				break;
			case SDL_QUIT:
				quit = true;
				break;
		}

		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}

