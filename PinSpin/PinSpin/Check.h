#ifndef Check_H
#define Check_H

#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  
#include "Randomizer.h"
#include <stdlib.h> 
#include <time.h>

bool check_key_match(std::vector<SDL_Texture*> password, int password_progress,
	SDL_Texture* numbers, SDL_Texture* colors, SDL_Texture* shapes, SDL_Texture* letters);
#endif