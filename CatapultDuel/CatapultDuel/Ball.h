#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Ball:
	public GameObject
{
private:	
	int ypozicija;	
	int orient;
	Sprite ball;
	Sprite clear;
public:
	int xpozicija;
	int pomak;
	int state; //0 nema, 1 start, 2 leti
	bool odbacen;
	bool pogodak;
	Ball();	
	Ball(HANDLE aHandle, int positionX, int positionY, int orientation);
	void OnUpdate();
	bool GetPogodak();
};

