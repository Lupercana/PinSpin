#ifndef Cell_H
#define Cell_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  
// Contains function that creates structs
struct cell {
	SDL_Surface* Number;
	SDL_Surface* Color;
	SDL_Surface* Shape;
	SDL_Surface* Letter;
};

#endif
