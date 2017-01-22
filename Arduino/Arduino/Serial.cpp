#include <stdio.h>
#include "stdafx.h"
#include <fstream>

using namespace std;

int main()
{
	int data[] = { 10,5,13 };  //Random data we want to send
	fstream file;
	file.open("/dev/ttyUSB0");  
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		file << data[i];
		fprintf(file, "%c", ','); //To separate digits


	}
	fclose(file);
}