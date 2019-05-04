#include "TheGame.h"
#include "Scene.h"
#include "Catapult.h"
#include<iostream>
#include <string>


TheGame::TheGame()
{
	origOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordDest;
	coordDest.X = 10;
	coordDest.Y = 5;
	DWORD cWritten;
	
	outHandle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,   
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	if (!SetConsoleActiveScreenBuffer(outHandle))
	{
		printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());		
	}

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); // Handle sa èitanje ulaza sa tastature
	DWORD fdwSaveOldMode; // Tu spremamo 
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	boolean endGame = false;	
	DWORD lpcNumberOfEvents;
    std::string message;

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		OutputDebugStringA("Nešto nije u redu sa GetConsoleMode!");

	fdwMode = ENABLE_EXTENDED_FLAGS & ~ENABLE_QUICK_EDIT_MODE; //Iskljuèit æemo miša da nam ne smeta
	if (!SetConsoleMode(hStdin, fdwMode))
		OutputDebugStringA("Nešto nije u redu sa SetConsoleMode!");

	//Postavljanje scene 
	Scene scena = Scene(outHandle);
	
	// Glavni loop izlaz sa ESC
	do
	{
		Sleep(18);
		if (!GetNumberOfConsoleInputEvents(hStdin, &lpcNumberOfEvents))
			OutputDebugStringA("Nešto ne valja sa GetNumberOfConsoleInputEvents");

		if (lpcNumberOfEvents > 0)
		{	
			/*message = "Ima input evenata: " + std::to_string(lpcNumberOfEvents) + "\n";
			OutputDebugString(message.c_str());*/
			if (!ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
				endGame = true;

			if (cNumRead > 0) {
				for (i = 0; i < cNumRead; i++)
					if (irInBuf[i].EventType == KEY_EVENT)
					{
						if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
							endGame = true;
						else
							scena.OnKeyPress(irInBuf[i].Event.KeyEvent.wVirtualKeyCode);
					}				
			}			
		}	
		scena.OnUpdate();
	} while (!endGame);

	// Na kraju treba vratiti stare kontrole 
	if (!SetConsoleMode(hStdin, fdwSaveOldMode))
		OutputDebugStringA("Nešto nije u redu sa SetConsoleMode!");
}


TheGame::~TheGame()
{
	if (!SetConsoleActiveScreenBuffer(origOutHandle))
	{
		printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
	}
}
