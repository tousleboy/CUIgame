#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Scene.h"

void Scene::Game() {
	std::system("cls");
	// �e���L�[ or wasd��@�}�[�N���ړ����邾���̃T���v��
	// �T���v���Ȃ̂ŏ����Ă����v�ł��B
	int x = 0; // X���W
	int y = 0; // Y���W
	int i; // �L�[���͒l
	do
	{
		printf("\x1b[%d;%dH@", y, x); // ���̍��W��'@'�\��
		i = _getch(); // �L�[���͑҂�
		printf("\x1b[%d;%dH ", y, x); // �O�̍��W��' '�\��
		// �L�[���͂ō��W�X�V
		switch (i) {
		case '2':
		case 's':
			++y;
			break;
		case '4':
		case 'a':
			--x;
			break;
		case '6':
		case 'd':
			++x;
			break;
		case '8':
		case 'w':
			--y;
			break;
		}
	} while ('q' != i); // 'q'�L�[�ŏI��
	Result();
}
