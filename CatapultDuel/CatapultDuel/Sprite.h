#pragma once
#include<Windows.h>
#include<string>
#include"UserType.h"

class Sprite
{
private:
	int width;
	int height;
	tSprite sprite;
	HANDLE outHandle;
	char convert(char16_t ch);
public:
	COORD position;
	Sprite();
	Sprite(HANDLE aHandle, tuSprite aSprite, int aWidth, int aHeight, int x, int y, int orientation);
	void Show();	
};

