// PinSpin.cpp : Application made during Spartahack 2017
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  

using namespace std;

// Misc
SDL_Surface* img_base = IMG_Load("../../images/pin_design_outline.png");
SDL_Surface* img_sel_outline = IMG_Load("../../images/selection_outline.png");

// Numbers
SDL_Surface* img_num_one = IMG_Load("../../images/numbers/one.png");
SDL_Surface* img_num_two = IMG_Load("../../images/numbers/two.png");
SDL_Surface* img_num_three = IMG_Load("../../images/numbers/three.png");
SDL_Surface* img_num_four = IMG_Load("../../images/numbers/four.png");
SDL_Surface* img_num_five = IMG_Load("../../images/numbers/five.png");
SDL_Surface* img_num_six = IMG_Load("../../images/numbers/six.png");
SDL_Surface* img_num_seven = IMG_Load("../../images/numbers/seven.png");
SDL_Surface* img_num_eight = IMG_Load("../../images/numbers/eight.png");
SDL_Surface* img_num_nine = IMG_Load("../../images/numbers/nine.png");

// Colors
SDL_Surface* img_color_black = IMG_Load("../../images/colors/black.png");
SDL_Surface* img_color_blue = IMG_Load("../../images/colors/blue.png");
SDL_Surface* img_color_green = IMG_Load("../../images/colors/green.png");
SDL_Surface* img_color_grey = IMG_Load("../../images/colors/grey.png");
SDL_Surface* img_color_orange = IMG_Load("../../images/colors/orange.png");
SDL_Surface* img_color_pink = IMG_Load("../../images/colors/pink.png");
SDL_Surface* img_color_red = IMG_Load("../../images/colors/red.png");
SDL_Surface* img_color_violet = IMG_Load("../../images/colors/violet.png");
SDL_Surface* img_color_yellow = IMG_Load("../../images/colors/yellow.png");


// Shapes
SDL_Surface* img_shapes_arrow = IMG_Load("../../images/shapes/arrow.png");
SDL_Surface* img_shapes_circle = IMG_Load("../../images/shapes/circle.png");
SDL_Surface* img_shapes_crescent = IMG_Load("../../images/shapes/crescent.png");
SDL_Surface* img_shapes_diamond = IMG_Load("../../images/shapes/diamond.png");
SDL_Surface* img_shapes_heart = IMG_Load("../../images/shapes/heart.png");
SDL_Surface* img_shapes_leaf = IMG_Load("../../images/shapes/leaf.png");
SDL_Surface* img_shapes_snowflake = IMG_Load("../../images/shapes/snowflake.png");
SDL_Surface* img_shapes_square = IMG_Load("../../images/shapes/square.png");
SDL_Surface* img_shapes_triangle = IMG_Load("../../images/shapes/triangle.png");


void display_cell_visuals(SDL_Renderer* renderer, vector<SDL_Texture*> &txt_numbers,
vector<SDL_Texture*> &txt_colors, vector<SDL_Texture*> &txt_shapes)
//vector<SDL_Texture*> txt_shapes)
{
	const int OFFSET = 5; // selection outline width
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
		SDL_Rect upper_right_rect = { x + OFFSET, y + OFFSET, BOX_SIZE, BOX_SIZE };
		SDL_Rect lower_left_rect = { x + OFFSET, y + OFFSET, BOX_SIZE, BOX_SIZE };
		//SDL_Rect lower_right_rect = { x + OFFSET, y + OFFSET, BOX_SIZE, BOX_SIZE };

		SDL_RenderCopy(renderer, txt_numbers.at(i), NULL, &upper_left_rect);
		SDL_RenderCopy(renderer, txt_colors.at(i), NULL, &upper_right_rect);
		SDL_RenderCopy(renderer, txt_shapes.at(i), NULL, &lower_left_rect);
		//SDL_RenderCopy(renderer, txt_numbers.at(i), NULL, &rect);

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
	SDL_Texture* txt_sel_outline = SDL_CreateTextureFromSurface(renderer, img_sel_outline);

	vector<SDL_Texture*> txt_numbers;
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_one));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_two));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_three));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_four));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_five));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_six));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_seven));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_eight));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_nine));

	vector<SDL_Texture*> txt_colors;
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_black));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_blue));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_green));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_grey));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_orange));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_pink));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_red));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_violet));
	txt_colors.push_back(SDL_CreateTextureFromSurface(renderer, img_color_yellow));

	
	vector<SDL_Texture*> txt_shapes;
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_arrow));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_circle));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_crescent));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_diamond));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_heart));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_leaf));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_snowflake));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_square));
	txt_shapes.push_back(SDL_CreateTextureFromSurface(renderer, img_shapes_triangle));

	/*
	vector<SDL_Texture*> txt_numbers;
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_one));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_two));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_three));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_four));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_five));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_six));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_seven));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_eight));
	txt_numbers.push_back(SDL_CreateTextureFromSurface(renderer, img_num_nine));
	*/
	while (!quit)
	{
		SDL_RenderClear(renderer);
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_1:
						current_press = 1;
						break;
					case SDLK_2:
						current_press = 2;
						break;
					case SDLK_3:
						current_press = 3;
						break;
					case SDLK_4:
						current_press = 4;
						break;
					case SDLK_5:
						current_press = 5;
						break;
					case SDLK_6:
						current_press = 6;
						break;
					case SDLK_7:
						current_press = 7;
						break;
					case SDLK_8:
						current_press = 8;
						break;
					case SDLK_9:
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

		display_cell_visuals(renderer, txt_numbers, txt_colors, txt_shapes); // TODO: pass in vector of cell contents
 		display_selection_outline(renderer, txt_sel_outline, current_press);

		SDL_RenderPresent(renderer);
	}

	// TODO: free everything, otherwise there'll be memory leak
	SDL_DestroyTexture(txt_base);
	SDL_FreeSurface(img_base);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}

