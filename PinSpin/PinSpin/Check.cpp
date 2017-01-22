#include "stdafx.h"
#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  
#include "Randomizer.h"
#include <stdlib.h> 
#include <time.h>

using namespace std;

bool check_key_match(std::vector<SDL_Texture*> password, int password_progress,
	SDL_Texture* numbers, SDL_Texture* colors, SDL_Texture* shapes, SDL_Texture* letters) {
	bool match = false;

	if (password_progress >= password.size())
		return false;

	if (password.at(password_progress) == numbers) {
		match = true;
	}
	if (password.at(password_progress) == colors) {
		match = true;
	}
	if (password.at(password_progress) == shapes) {
		match = true;
	}
	if (password.at(password_progress) == letters) {
		match = true;
	}
	return match;
}