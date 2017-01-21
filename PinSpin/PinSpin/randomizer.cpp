#include "stdafx.h"
#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  
#include "Randomizer.h"
#include <string>
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
	srand(time(NULL));
	int randnum;
	bool repeat = false;
	while ( used.size() < size) {
		randnum = rand() % size;
		for (int i = 0; i < used.size(); i++) {
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