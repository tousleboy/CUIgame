#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Scene.h"

void Scene::Title() {
	std::system("cls");
	std::cout << "Title" << std::endl;
	int i; //����
	do
	{
		i = _getch(); // �L�[���͑҂�
	} while ('q' != i && 's' != i);
	if ('s' == i) Game();
}
