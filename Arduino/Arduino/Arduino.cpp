// Arduino.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int j = 5;

int main()
{
	fstream arduino;
	arduino.open("/dev/ttyACM0", ios::in | ios::out);
	//Opening device file

	if (!arduino)
		cout << "error";
	arduino << 2;
	arduino.clear();
	arduino >> j;
	cout << j;
	arduino.close();
    return 0;
}

