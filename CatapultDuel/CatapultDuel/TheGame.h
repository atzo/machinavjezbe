#pragma once
#include<Windows.h>

class TheGame
{
	HANDLE origOutHandle;
	HANDLE inHandle;
	HANDLE outHandle;
public:
	TheGame();
	~TheGame();
};

