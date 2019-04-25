#pragma once
#include<Windows.h>
#include<iostream>
#include<string>

class Score
{
private:
	HANDLE outHandle;
	std::string title;
	char *title1;
	int helt;
	COORD scoreCord;
	void printSscore();
public:
	Score();
	Score(HANDLE aHandle, char *aTitle, int x, int y);
	void decHelt();
	bool isEndGame();
};

