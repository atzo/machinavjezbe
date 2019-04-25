#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(HANDLE aHandle, int positionX, int positionY)
{
	handle = aHandle;
	position.X = positionX;
	position.Y = positionY;	
	changed = true;
}

void GameObject::OnKeyPress(WORD keyCode)
{
}

void GameObject::OnUpdate()
{
}