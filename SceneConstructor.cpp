#include <windows.h>
#include <stdio.h>
#include "Scene.h"

const size_t MAXSIZE = 100;

Scene::Scene() {
	// エスケープシーケンスを有効に
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// カーソルを消す
	printf("\x1b[?25l");
	Title();
}

Scene::~Scene() {
	// カーソルを表示
	printf("\x1b[?25h");
}