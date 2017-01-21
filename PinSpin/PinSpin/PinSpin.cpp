// PinSpin.cpp : Application made during Spartahack 2017
//

#include "stdafx.h"
#include <iostream>
#include <include/SDL.h>   
#include <include/SDL_image.h>  

using namespace std;

SDL_Surface* img_base = IMG_Load("../../images/pin_design_outline.png");
SDL_Surface* img_sel_outline = IMG_Load("../../images/selection_outline.png");

void display_selection_outline(SDL_Renderer* renderer, int current_press)
{
	SDL_Texture* txt_sel_outline = SDL_CreateTextureFromSurface(renderer, img_sel_outline);
	const int OUTLINE_SIZE = 156;
	int x = 0;
	int y = 0;

	switch (current_press)
	{
		case 1:
			x = 0;
			y = 324;
			break;
		case 2:
			x = 162;
			y = 324;
			break;
		case 3:
			x = 324;
			y = 324;
			break;
		case 4:
			x = 0;
			y = 162;
			break;
		case 5:
			x = 162;
			y = 162;
			break;
		case 6:
			x = 324;
			y = 162;
			break;
		case 7:
			x = 0;
			y = 0;
			break;
		case 8:
			x = 162;
			y = 0;
			break;
		case 9:
			x = 324;
			y = 0;
			break;
	}

	SDL_Rect rect = {x, y, OUTLINE_SIZE, OUTLINE_SIZE};

	if (current_press != 0)
		SDL_RenderCopy(renderer, txt_sel_outline, NULL, &rect);
}

int main(int argc, char ** argv)
{
	int current_press = 0;
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_Window * window = SDL_CreateWindow("Application",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 480, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture* txt_base = SDL_CreateTextureFromSurface(renderer, img_base);

	while (!quit)
	{
		SDL_RenderClear(renderer);
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_KP_1:
						current_press = 1;
						break;
					case SDLK_KP_2:
						current_press = 2;
						break;
					case SDLK_KP_3:
						current_press = 3;
						break;
					case SDLK_KP_4:
						current_press = 4;
						break;
					case SDLK_KP_5:
						current_press = 5;
						break;
					case SDLK_KP_6:
						current_press = 6;
						break;
					case SDLK_KP_7:
						current_press = 7;
						break;
					case SDLK_KP_8:
						current_press = 8;
						break;
					case SDLK_KP_9:
						current_press = 9;
						break;
					default:
						cout << "Unmapped key press." << endl;
						break;
				}
				break;
			case SDL_KEYUP:
				current_press = 0;
				break;
			case SDL_QUIT:
				quit = true;
				break;
		}

		// Display the base first for layering to work
		SDL_RenderCopy(renderer, txt_base, NULL, NULL);

		display_selection_outline(renderer, current_press);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(txt_base);
	SDL_FreeSurface(img_base);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}

