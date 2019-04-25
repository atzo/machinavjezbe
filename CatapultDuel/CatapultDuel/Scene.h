#pragma once
#include<Windows.h>
#include"Catapult.h"
#include"Ball.h"
#include "Score.h"

class Scene
{
private:
	HANDLE outHandle;
	Catapult katapult1;
	Catapult katapult2;
	Ball ball1;
	Ball ball2;
	Score theScore1;
	Score theScore2;
	int gameObjectCount;
	void showKeys(HANDLE aHandle);
public:
	Scene();
	Scene(HANDLE aHandle);
	void OnUpdate();
	void OnKeyPress(WORD keyCode);
};

