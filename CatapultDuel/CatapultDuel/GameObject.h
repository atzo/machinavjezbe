#pragma once
#include<Windows.h>

class GameObject
{
public:
	COORD position;
	boolean changed;
	HANDLE handle;
	GameObject();
	GameObject(HANDLE aHandle, int positionX, int positionY);
	void OnKeyPress(WORD keyCode);
	void OnUpdate();
};

