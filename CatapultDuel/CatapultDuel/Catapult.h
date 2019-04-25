#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Catapult: 
	public GameObject
{
private:
	Sprite catapultReady;
	Sprite catapultFire;
	Sprite ball;
	Sprite defender;
	WORD nategni;
	WORD napuni;
	WORD ispali;
	WORD brani;
	
public:
	int state; //0 nategnut, 1 napunjen, 2 ispaljen
	int braniState; //0 spreman, 1 ide gore, 2 vraæa se dolje, 3 inicijalno iscrtavanje
	int defenderPosY;
	int defenderPosX;
    Catapult();
	Catapult(HANDLE aHandle, int positionX, int positionY, int orientation);
	void SetKeys(WORD aNategni, WORD aNapuni, WORD aIspali, WORD aBrani);
	void OnKeyPress(WORD keyCode);
	void OnUpdate();
	void AnimateDefender();
	bool isCach();
};

