// PinSpin.cpp : Application made during Spartahack 2017
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  
#include "Randomizer.h"
#include <stdlib.h> 
#include <time.h>
#include "Check.h"

using namespace std;

// Misc
SDL_Surface* img_base = IMG_Load("../../images/pin_design_outline.png");
SDL_Surface* img_sel_outline = IMG_Load("../../images/selection_outline.png");

// Numbers
vector<SDL_Surface*> img_numbers {	IMG_Load("../../images/numbers/one.png"),
									IMG_Load("../../images/numbers/two.png"),
									IMG_Load("../../images/numbers/three.png"),
									IMG_Load("../../images/numbers/four.png"),
									IMG_Load("../../images/numbers/five.png"),
									IMG_Load("../../images/numbers/six.png"),
									IMG_Load("../../images/numbers/seven.png"),
									IMG_Load("../../images/numbers/eight.png"),
									IMG_Load("../../images/numbers/nine.png") };

// Colors
vector<SDL_Surface*> img_colors{    IMG_Load("../../images/colors/black.png"),
									IMG_Load("../../images/colors/blue.png"),
									IMG_Load("../../images/colors/green.png"),
									IMG_Load("../../images/colors/grey.png"),
									IMG_Load("../../images/colors/orange.png"),
									IMG_Load("../../images/colors/pink.png"),
									IMG_Load("../../images/colors/red.png"),
									IMG_Load("../../images/colors/violet.png"),
									IMG_Load("../../images/colors/yellow.png") };

// Shapes
vector<SDL_Surface*> img_shapes{    IMG_Load("../../images/shapes/arrow.png"),
									IMG_Load("../../images/shapes/circle.png"),
									IMG_Load("../../images/shapes/crescent.png"),
									IMG_Load("../../images/shapes/diamond.png"),
									IMG_Load("../../images/shapes/heart.png"),
									IMG_Load("../../images/shapes/leaf.png"),
									IMG_Load("../../images/shapes/snowflake.png"),
									IMG_Load("../../images/shapes/square.png"),
									IMG_Load("../../images/shapes/triangle.png") };

// Leters
vector<SDL_Surface*> img_letters{   IMG_Load("../../images/letters/A.png"),
									IMG_Load("../../images/letters/B.png"),
									IMG_Load("../../images/letters/C.png"),
									IMG_Load("../../images/letters/D.png"),
									IMG_Load("../../images/letters/E.png"),
									IMG_Load("../../images/letters/F.png"),
									IMG_Load("../../images/letters/G.png"),
									IMG_Load("../../images/letters/H.png"),
									IMG_Load("../../images/letters/I.png") };


void remove_img(SDL_Surface* img) {
	SDL_FreeSurface(img);
	return;

}

void display_cell_visuals(SDL_Renderer* renderer, vector<SDL_Texture*> &txt_numbers,
vector<SDL_Texture*> &txt_colors, vector<SDL_Texture*> &txt_shapes, vector<SDL_Texture*> &txt_letters)
{
	const int OFFSET = 5; // selection outline width
	const int CELL_LENGTH = 78; // width/length of a box
	const int BOX_SIZE = 50;
	int x;
	int y;

	// TODO: update to reflect actual cell content values
	for (int i = 0; i < (int)txt_numbers.size(); i++)
	{
		switch (i + 1)
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
		SDL_Rect upper_left_rect = {x + OFFSET, y + OFFSET, BOX_SIZE, BOX_SIZE};
		SDL_Rect upper_right_rect = { x + OFFSET + CELL_LENGTH, y + OFFSET, BOX_SIZE, BOX_SIZE };
		SDL_Rect lower_left_rect = { x + OFFSET, y + OFFSET + CELL_LENGTH, BOX_SIZE, BOX_SIZE };
		SDL_Rect lower_right_rect = { x + OFFSET + CELL_LENGTH, y + OFFSET + CELL_LENGTH, BOX_SIZE, BOX_SIZE };

		SDL_RenderCopy(renderer, txt_numbers.at(i), NULL, &upper_left_rect);
		SDL_RenderCopy(renderer, txt_colors.at(i), NULL, &upper_right_rect);
		SDL_RenderCopy(renderer, txt_shapes.at(i), NULL, &lower_left_rect);
		SDL_RenderCopy(renderer, txt_letters.at(i), NULL, &lower_right_rect);

	}
}

void display_selection_outline(SDL_Renderer* renderer, SDL_Texture* txt_sel_outline, int current_press)
{
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
		case 10:
			x = 0;
			y = 486;
			break;
		case 11:
			x = 162;
			y = 486;
			break;
		case 12:
			x = 324;
			y = 486;
			break;
	}

	SDL_Rect rect = {x, y, OUTLINE_SIZE, OUTLINE_SIZE};

	if (current_press != 0)
		SDL_RenderCopy(renderer, txt_sel_outline, NULL, &rect);
}

int main(int argc, char ** argv)
{
	srand(time(NULL));
	int current_press = 0;
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_Window * window = SDL_CreateWindow("Virtual Keypad",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 640, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture* txt_base = SDL_CreateTextureFromSurface(renderer, img_base);
	SDL_Texture* txt_sel_outline = SDL_CreateTextureFromSurface(renderer, img_sel_outline);

	vector<SDL_Texture*> txt_numbers;
	for (unsigned int i = 0; i < img_numbers.size(); i++) {
		txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_numbers.at(i)));
	}
	vector<SDL_Texture*> rand_txt_numbers = randomizer(txt_numbers);

	vector<SDL_Texture*> txt_colors;
	for (unsigned int i = 0; i < img_colors.size(); i++) {
		txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_colors.at(i)));
	}
	vector<SDL_Texture*> rand_txt_colors= randomizer(txt_colors);

	vector<SDL_Texture*> txt_shapes;
	for (unsigned int i = 0; i < img_shapes.size(); i++) {
		txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes.at(i)));
	}
	vector<SDL_Texture*> rand_txt_shapes = randomizer(txt_shapes);

	
	vector<SDL_Texture*> txt_letters;
	for (unsigned int i = 0; i < img_letters.size(); i++) {
		txt_letters.push_back(SDL_CreateTextureFromSurface(renderer, img_letters.at(i)));
	}
	vector<SDL_Texture*> rand_txt_letters = randomizer(txt_letters);

	vector< SDL_Texture*> password;
	generatePassword(4, txt_numbers, txt_colors, txt_shapes, txt_letters, password);
	int password_progress = 0;
	bool password_match = true;
	while (!quit)
	{
		SDL_RenderClear(renderer);
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			int index;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_KP_1:
						index = 0;
						current_press = 1;
						break;
					case SDLK_KP_2:
						index = 1;
						current_press = 2;
						break;
					case SDLK_KP_3:
						index = 2;
						current_press = 3;
						break;
					case SDLK_KP_4:
						index = 3;
						current_press = 4;
						break;
					case SDLK_KP_5:
						index = 4;
						current_press = 5;
						break;
					case SDLK_KP_6:
						index = 5;
						current_press = 6;
						break;
					case SDLK_KP_7:
						index = 6;
						current_press = 7;
						break;
					case SDLK_KP_8:
						index = 7;
						current_press = 8;
						break;
					case SDLK_KP_9:
						index = 8;
						current_press = 9;
						break;
					case SDLK_RIGHT: // password check
						index = -1;
						if (password_match == true && password_progress == password.size())
							cout << "You got the right password!" << endl;
						else
							cout << "You got the wrong password!" << endl;
						password_match = true;
						password_progress = 0;
						current_press = 10;
						break;
					case SDLK_KP_0: // generate new password
						index = -1;
						generatePassword(4, txt_numbers, txt_colors, txt_shapes, txt_letters, password);
						current_press = 11;
						break;
					case SDLK_KP_PERIOD: // password reset progress 
						index = -1;
						password_match = true;
						password_progress = 0;
						current_press = 12;
						break;
					default:
						index = -1;
						cout << "Unmapped key press." << endl;
						break;
				}
				if (index != -1)
				{
					if (password_match = check_key_match(password, password_progress,
						rand_txt_numbers.at(index), rand_txt_colors.at(index), rand_txt_shapes.at(index),
						rand_txt_letters.at(index))) // did this on purpose
						password_progress++;
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

		display_cell_visuals(renderer, rand_txt_numbers, rand_txt_colors, rand_txt_shapes, rand_txt_letters);
 		display_selection_outline(renderer, txt_sel_outline, current_press);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(txt_base);
	SDL_FreeSurface(img_base);
	SDL_DestroyTexture(txt_sel_outline);
	SDL_FreeSurface(img_sel_outline);

	for (unsigned int i = 0; i < txt_numbers.size(); i++) {
		SDL_DestroyTexture(txt_numbers.at(i));
		SDL_DestroyTexture(txt_shapes.at(i));
		SDL_DestroyTexture(txt_letters.at(i));
		SDL_DestroyTexture(txt_colors.at(i));		
	}

	for (unsigned int i = 0; i < img_colors.size(); i++) {
		SDL_FreeSurface(img_numbers.at(i));
		SDL_FreeSurface(img_shapes.at(i));
		SDL_FreeSurface(img_letters.at(i));
		SDL_FreeSurface(img_colors.at(i));
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}

