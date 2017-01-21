#ifndef Random_H
#define Random_H

#include <vector>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  

std :: vector<SDL_Texture*> randomizer( std::vector<SDL_Texture*> & v);

void generatePassword(int password_length, std::vector<SDL_Texture*> &txt_numbers, std::vector<SDL_Texture*> &txt_colors,
	std::vector<SDL_Texture*> &txt_shapes, std::vector<SDL_Texture*> &txt_letters,
	std::vector<SDL_Texture*> &password);
#endif
