#include <iostream>
#include <vector>
#include <include/SDL.h>   
#include <include/SDL_image.h>  
#include "Randomizer.h"
#include <stdlib.h> 
#include <time.h>

using namespace std;

vector<SDL_Texture*> randomizer(vector<SDL_Texture*> & v) {
	int size = v.size();
	vector <int> used; 
	vector<SDL_Texture*> vrand;
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
			vrand.push_back(v[randnum]);
		}
	}
	return vrand;
}

void generatePassword(int password_length, vector<SDL_Texture*> &txt_numbers, 
	vector<SDL_Texture*> &txt_colors, vector<SDL_Texture*> &txt_shapes, vector<SDL_Texture*> &txt_letters,
	vector<SDL_Texture*> &password)
{
	int v1, v2;

	password.resize(password_length);

	cout << "\nPassword:" << endl;
	for (int i = 0; i < password_length; i++) {
		v1 = rand() % 4;
		v2 = rand() % 9;

		if (v1 == 0)
			password.at(i) = txt_numbers.at(v2);
		else if (v1 == 1)
			password.at(i) = txt_colors.at(v2);
		else if (v1 == 2)
			password.at(i) = txt_shapes.at(v2);
		else if (v1 == 3)
			password.at(i) = txt_letters.at(v2);

		for (unsigned int j = 0; j < txt_numbers.size(); j++)
		{
			if (password.at(i) == txt_numbers.at(j))
			{
				switch (j)
				{
					case 0:
						cout << "One" << endl;
						break;
					case 1:
						cout << "Two" << endl;
						break;
					case 2:
						cout << "Three" << endl;
						break;
					case 3:
						cout << "Four" << endl;
						break;
					case 4:
						cout << "Five" << endl;
						break;
					case 5:
						cout << "Six" << endl;
						break;
					case 6:
						cout << "Seven" << endl;
						break;
					case 7:
						cout << "Eight" << endl;
						break;
					case 8:
						cout << "Nine" << endl;
						break;
				}
			}
		}

		for (unsigned int j = 0; j < txt_colors.size(); j++)
		{
			if (password.at(i) == txt_colors.at(j))
			{
				switch (j)
				{
					case 0:
						cout << "Black" << endl;
						break;
					case 1:
						cout << "Blue" << endl;
						break;
					case 2:
						cout << "Green" << endl;
						break;
					case 3:
						cout << "Gray" << endl;
						break;
					case 4:
						cout << "Orange" << endl;
						break;
					case 5:
						cout << "Pink" << endl;
						break;
					case 6:
						cout << "Red" << endl;
						break;
					case 7:
						cout << "Violet" << endl;
						break;
					case 8:
						cout << "Yellow" << endl;
						break;
				}
			}
		}

		for (unsigned int j = 0; j < txt_shapes.size(); j++)
		{
			if (password.at(i) == txt_shapes.at(j))
			{
				switch (j)
				{
					case 0:
						cout << "Arrow" << endl;
						break;
					case 1:
						cout << "Circle" << endl;
						break;
					case 2:
						cout << "Crescent" << endl;
						break;
					case 3:
						cout << "Diamond" << endl;
						break;
					case 4:
						cout << "Heart" << endl;
						break;
					case 5:
						cout << "Clover" << endl;
						break;
					case 6:
						cout << "Snowflake" << endl;
						break;
					case 7:
						cout << "Square" << endl;
						break;
					case 8:
						cout << "Triangle" << endl;
						break;
				}
			}
		}

		for (unsigned int j = 0; j < txt_letters.size(); j++)
		{
			if (password.at(i) == txt_letters.at(j))
			{
				switch (j)
				{
					case 0:
						cout << "A" << endl;
						break;
					case 1:
						cout << "B" << endl;
						break;
					case 2:
						cout << "C" << endl;
						break;
					case 3:
						cout << "D" << endl;
						break;
					case 4:
						cout << "E" << endl;
						break;
					case 5:
						cout << "F" << endl;
						break;
					case 6:
						cout << "G" << endl;
						break;
					case 7:
						cout << "H" << endl;
						break;
					case 8:
						cout << "I" << endl;
						break;
				}
			}
		}
	}
}