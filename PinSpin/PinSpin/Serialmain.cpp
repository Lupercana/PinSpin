#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>

// application reads from the specified serial port and reports the collected data
void _tmain(int argc, _TCHAR* argv[])
{
	printf("Welcome to the serial test app!\n\n");

	Serial* SP = new Serial("\\\\.\\COM4");    // adjust as needed

	if (SP->IsConnected())
		printf("We're connected");

	char incomingData[] = "1";			// don't forget to pre-allocate memory
											//printf("%s\n",incomingData);
	int dataLength = 1;
	int readResult = 0;

	//while (SP->IsConnected())
	if (SP->IsConnected())
	{
		printf("%d", SP->WriteData(incomingData, dataLength));
		// printf("Bytes read: (0 means no data available) %i\n",readResult);
		//incomingData[readResult] = 0;

		//printf("%s", incomingData);

		Sleep(500);
	}

	delete SP;
	system("pause");

}