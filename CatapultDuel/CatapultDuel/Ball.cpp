#pragma once
#include <math.h> 
#include "Ball.h"
#include "UserType.h"


#define PI 3.14159265

tuSprite sp5 = {
	u"                  ",
	u"  ▄██▄            ",
	u"  ▀██▀            ",
	u"                  ",
	u"                  ",
	u"                  ",
	u"                  ",
	u"                  " };

tuSprite sp6 = {
	u"                  ",
	u"                  ",
	u"                  ",
	u"                  ",
	u"                  ",
	u"                  ",
	u"                  ",
	u"                  " };


Ball::Ball()
{
}

Ball::Ball(HANDLE aHandle, int positionX, int positionY, int orientation)
{
	handle = aHandle;
	pogodak = false;
	position.X = positionX;
	position.Y = positionY;
	xpozicija = positionX;
	ypozicija = positionY;
	pomak = 0;
	state = 0;
	odbacen = false;
	orient = orientation;
	ball = Sprite(handle, sp5, 8, 4, position.X, position.Y, 1);
	clear = Sprite(handle, sp6, 6, 7, position.X, position.Y, 1);
}

void Ball::OnUpdate()
{
	if (state > 0)
	{

		if (state == 1)
		{
			pomak = 0;
			state = 2;
		}
		else
		{
			pomak = pomak + orient;
		}

		ball.position.X = xpozicija - pomak;
		if (odbacen)
			--ball.position.Y;
		else
			ball.position.Y = ypozicija + std::sin(PI + 0.5 + (PI / 80)*std::abs(pomak)) * (ypozicija - 5);

		if (orient > 0 && ball.position.X > 12 || orient < 0 && ball.position.X < 102) {
			ball.Show();
			clear.position = ball.position;
		}
		else
		{
			clear.Show();
			pogodak = !odbacen;			
			state = 0;
			odbacen = false;
		}
	}
}

bool Ball::GetPogodak()
{
	bool tmp = pogodak;
	pogodak = false;
	return tmp;	
}