#include "stdafx.h"
#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  
#include "Randomizer.h"
#include <stdlib.h> 
#include <time.h>

using namespace std;

void randomizer(vector<SDL_Texture*> & v) {
	int size = v.size();
	vector< SDL_Texture*> vtemp;
	for (int i = 0; i < size; i++) {
		vtemp.push_back(v.at(i));
	}
	vector <int> used; 
	v.clear();
	int randnum;
	bool repeat = false;
	while ( (int)used.size() < size) {
		randnum = rand() % size;
		for (int i = 0; i < (int)used.size(); i++) {
			if (used.at(i) == randnum) {
				repeat = true;
			}
		}
		if (repeat == true)
		{
			repeat = false;
		}
		else {
			used.push_back(randnum);
			v.push_back(vtemp[randnum]);
		}
	}

}

void generatePassword(int password_length, vector<SDL_Texture*> &txt_numbers, 
	vector<SDL_Texture*> &txt_colors, vector<SDL_Texture*> &txt_shapes, vector<SDL_Texture*> &txt_letters,
	vector<SDL_Texture*> &password)
{
	int v1, v2;

	for (int i = 0; i < password_length; i++) {
		v1 = rand() % 4;
		v2 = rand() % 9;
		cout << v1 << " " << v2 << endl;
		if (v1 == 0)
			password.push_back(txt_numbers.at(v2));
		else if (v1 == 1)
			password.push_back(txt_colors.at(v2));
		else if (v1 == 2)
			password.push_back(txt_shapes.at(v2));
		else if (v1 == 3)
			password.push_back(txt_shapes.at(v2));
	}
}