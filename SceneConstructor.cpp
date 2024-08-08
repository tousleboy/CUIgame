#include <windows.h>
#include <stdio.h>
#include "Scene.h"

Scene::Scene() {
	// �G�X�P�[�v�V�[�P���X��L����
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// �J�[�\��������
	printf("\x1b[?25l");
	Title();
}

Scene::~Scene() {
	// �J�[�\����\��
	printf("\x1b[?25h");
}