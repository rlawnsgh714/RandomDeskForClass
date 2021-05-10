#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable : 4996)

int sit[21];

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

enum colorName
{
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void drw(int bgColor, int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}

void random(int sit[])
{
	int i, rnd, temp;

	for (i = 0; i < 20; i++)
	{
		rnd = rand() % 20;
		temp = sit[rnd];
		sit[rnd] = sit[i];
		sit[i] = temp;
	}
}
void seat_arrangement(int row, int column)

{
	
	srand(time(NULL));
	int sit[100] = { 0 };
	int total, i, j, count = 0;

	total = row * column;
	for (i = 0; i < total; i++)
	{
		sit[i] = i + 1;
	}
	random(sit);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= column; j++)
		{
			gotoxy(j * 6 + 1, i * 4);
			printf("%2d", sit[count]);
			//Sleep(1000);
			count++;
		}
	}
}
void seat_arrangement1(int row, int column)

{

	srand(time(NULL));
	int sit[100] = { 0 };
	int total, i, j, count = 0;

	total = row * column;
	for (i = 0; i < total; i++)
	{
		sit[i] = i + 1;
	}
	random(sit);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= column; j++)
		{
			gotoxy(j * 6 + 1, i * 4);
			printf("%2d", sit[count]);
			Sleep(1000);
			count++;
		}
	}
}


void background()
{
	gotoxy(4, 2);
	printf("┏━━┳━━┳━━┳━━┓");
	gotoxy(4, 3);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 4);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 5);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 6);
	printf("┣━━╋━━╋━━╋━━┫");
	gotoxy(4, 7);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 8);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 9);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 10);
	printf("┣━━╋━━╋━━╋━━┫");
	gotoxy(4, 11);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 12);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 13);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 14);
	printf("┣━━╋━━╋━━╋━━┫");
	gotoxy(4, 15);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 16);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 17);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 18);
	printf("┣━━╋━━╋━━╋━━┫");
	gotoxy(4, 19);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 20);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 21);
	printf("┃    ┃    ┃    ┃    ┃");
	gotoxy(4, 22);
	printf("┗━━┻━━┻━━┻━━┛");
	gotoxy(4, 24);
	printf("┏━━━━━━━━━━━┓");
	gotoxy(4, 25);
	printf("           칠판           ");
}

int main()
{
	char k;
	background();
	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			seat_arrangement(5, 4);
			gotoxy(1, 1);
			printf("다시 하시겠습니까?(y : SPACE or TAP / n : ESCAPE)  ");
		}
		if (GetAsyncKeyState(VK_TAB))
		{
			seat_arrangement1(5, 4);
			gotoxy(1, 1);
			printf("다시 하시겠습니까?(y : SPACE or TAP / n : ESCAPE)  ");
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			gotoxy(1, 25);
			return 0;
		}
	}
	gotoxy(1, 25);
	return 0;
}