#include "Sprite.h"
#include "UserType.h"

Sprite::Sprite()
{
}

Sprite::Sprite(HANDLE aHandle, tuSprite aSprite, int aWidth, int aHeight, int x, int y, int orientation)
{
	outHandle = aHandle;
	position.X = x;
	position.Y = y;
	width = aWidth;
	height = aHeight;
	if (orientation > 0)
		for (int i = 0; i < spriteHeight; ++i)
			for (int j = 0; j < sptiteWidth; ++j)
				sprite[i][j] = convert(aSprite[i][j]);
	else
		for (int i = 0; i < spriteHeight; ++i)
			for (int j = 0; j < sptiteWidth; ++j)
				sprite[i][(sptiteWidth-1)-j] = convert(aSprite[i][j]);
}

void Sprite::Show()
{
	DWORD cWritten;
	std::string otuText = "";
	COORD tPosition = position;
	LPCSTR tmpLine;
	
	for (int i = 0; i < height; ++i)
	{		
		tmpLine = sprite[i];
		if (!WriteConsoleOutputCharacter(outHandle, tmpLine, width, tPosition, &cWritten))
		{
			OutputDebugStringA("Nesto ne valja sa WriteConsoleOutputCharacter");
		}

		++tPosition.Y;		
	}		
}

char Sprite::convert(char16_t ch)
{
	char ret_val;
	switch (ch)
	{
	case u'█': ret_val = char(219); break;
	case u'▀': ret_val = char(223); break;
	case u'▄': ret_val = char(220); break;
	case u'■': ret_val = char(224); break;
	default: ret_val = ' ';	break;
	}

	return ret_val;
}
