#include "Catapult.h"
#include "Sprite.h"
#include "SpriteDef.h"

Catapult::Catapult()
{
	GameObject::GameObject();
}

Catapult::Catapult(HANDLE aHandle, int positionX, int positionY, int orientation)
{
	handle = aHandle;
	position.X = positionX;
	position.Y = positionY;	
	catapultReady = Sprite(handle, sp1, 19, 8, position.X, position.Y, orientation);
	catapultFire = Sprite(handle, sp2, 19, 8, position.X, position.Y, orientation);
	if (orientation > 0)
	{
		ball = Sprite(handle, sp3, 4, 2, position.X + 14, position.Y + 5, 1);
		defender = Sprite(handle, sp4, 3, 3, position.X - 8, position.Y + 5, 1);		
	}
	else
	{
		ball = Sprite(handle, sp3, 4, 2, position.X + 1, position.Y + 5, 1);
		defender = Sprite(handle, sp4, 3, 3, position.X + 24, position.Y + 5, 1);
	}
	changed = true;
	state = 0;
	defenderPosY = defender.position.Y;
	defenderPosX = defender.position.X;
	braniState = 3;
}

void Catapult::SetKeys(WORD aNategni, WORD aNapuni, WORD aIspali, WORD aBrani)
{
	nategni = aNategni;
	napuni = aNapuni;
	ispali = aIspali;
	brani = aBrani;
}

void Catapult::OnKeyPress(WORD keyCode)
{
	
	if (keyCode == ispali)
	{
		if (state == 1)
		{
			changed = true;
			state = 2;
		}
	}
	else if (keyCode == nategni)
	{
		changed = state != 0;
		state = 0;
	}
	else if (keyCode == napuni)
	{
		if (state == 0)
		{
			changed = state != 1;
			state = 1;
		}
	}
	else if (keyCode == brani)
	{
		if (braniState == 0)
			braniState = 1;
	}
	else
	{
		changed = false;
	}
}

void Catapult::OnUpdate()
{
	if (changed)
		switch (state)
		{
		case 0: 
			catapultReady.Show(); 
			break;
		case 1: 
			catapultReady.Show();
			ball.Show(); 			
			break;
		case 2: 
			catapultFire.Show(); 
			break;
		default:			
			break;
		}
		

	AnimateDefender();
	changed = false;
}

void Catapult::AnimateDefender()
{
	if (braniState > 0) 
	{
		switch (braniState)
		{
		case 1:
		{
			if (defender.position.Y > defenderPosY - 5)
				--defender.position.Y;
			else
				braniState = 2;
			break;
		}
		case 2:
		{
			if (defender.position.Y < defenderPosY)
				++defender.position.Y;
			else
				braniState = 0;
			break;
		}
		case 3:
		{
			braniState = 0;
			break;
		}
		default:
			break;
		}

		defender.Show();
	}	
}

bool Catapult::isCach()
{
	if (defender.position.Y < defenderPosY - 1)
		return true;
	else
		return false;	
}


