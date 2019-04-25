#include "Score.h"

Score::Score()
{
}

Score::Score(HANDLE aHandle, char *aTitle, int x, int y)
{
	outHandle = aHandle;
	title = aTitle;
	helt = 20;
	scoreCord.X = x;
	scoreCord.Y = y;
	printSscore();
}

void Score::printSscore()
{
	DWORD cWritten;
	std::string otuText = title + std::to_string(helt) + "  ";
	if (!WriteConsoleOutputCharacter(outHandle, otuText.c_str(), otuText.length(), scoreCord, &cWritten))
	{
		std::cout << "nesto je krivo pošlo" << std::endl;
	}

	if (helt < 1) {
		scoreCord.X = 42;
		scoreCord.Y = 12;
		std::string otuText = "The " + title + "is a big looser!";
		if (!WriteConsoleOutputCharacter(outHandle, otuText.c_str(), otuText.length(), scoreCord, &cWritten))
		{
			std::cout << "nesto je krivo pošlo" << std::endl;
		}
	}
}

void Score::decHelt()
{
	--helt;
	printSscore();
}

bool Score::isEndGame()
{
	if (helt < 1)
		return true;
	else
		return false;
}
