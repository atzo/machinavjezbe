#include "Scene.h"
#include "Catapult.h"
#include <string>

Scene::Scene()
{
	
}

Scene::Scene(HANDLE aHandle)
{
	outHandle = aHandle;
	char player1[20] = "Player1: ";
	char player2[20] = "Player2: ";
	theScore1 = Score(outHandle, player1, 3, 2);
	theScore2 = Score(outHandle, player2, 105, 2);
	katapult1 = Catapult(outHandle, 100, 21, 1);
	katapult1.SetKeys(VK_RIGHT, VK_DOWN, VK_LEFT, VK_UP);
	ball1 = Ball(outHandle, 92, 19, 1);	
	katapult2 = Catapult(outHandle, 1, 21, -1);
	katapult2.SetKeys(0X41, 0X53, 0X44, 0X57); //ASDW
	ball2 = Ball(outHandle, 20, 19, -1);	
	showKeys(outHandle);
}

void Scene::showKeys(HANDLE aHandle)
{
	DWORD cWritten;
	COORD helpCord;
	helpCord.X = 1;
	helpCord.Y = 0;
	std::string otuText = "pull: A, load: S, fire: D, defend: W       Quit: ESC      pull: right, load down, fire: right, defend: up (arrow keys)";
	if (!WriteConsoleOutputCharacter(aHandle, otuText.c_str(), otuText.length(), helpCord, &cWritten))
	{
		std::cout << "nesto je krivo pošlo" << std::endl;
	}
}

void Scene::OnUpdate()
{
	if (theScore1.isEndGame() || theScore2.isEndGame())
		return;

	std::string  message;
	katapult1.OnUpdate();
	katapult2.OnUpdate();
	/*message = "katapult1.state: " + std::to_string(katapult1.state) + "\n";
			OutputDebugString(message.c_str());*/
	
	if (katapult1.state == 2 && ball1.state == 0)
	{
		katapult1.state = 3;
		ball1.state = 1;
	}

	if (katapult2.state == 2 && ball2.state == 0)
	{
		katapult2.state = 3;
		ball2.state = 1;
	}

	ball1.OnUpdate();
	ball2.OnUpdate();

	katapult2.OnUpdate();

	if(ball1.xpozicija - ball1.pomak == katapult2.defenderPosX - 4
		&& katapult2.isCach())
		ball1.odbacen = true;

	if (ball2.xpozicija - ball2.pomak == katapult1.defenderPosX - 2
		&& katapult1.isCach())
		ball2.odbacen = true;

	if (ball1.GetPogodak())
		theScore1.decHelt();

	if (ball2.GetPogodak())
		theScore2.decHelt();
}

void Scene::OnKeyPress(WORD keyCode)
{
	katapult1.OnKeyPress(keyCode);
	katapult2.OnKeyPress(keyCode);
}