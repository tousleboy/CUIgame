#include <iostream>
#include <conio.h>
#include "Scene.h"

void Scene::Result() {
	std::system("cls");
	std::cout << "Result" << std::endl;
	int i; //����
	do
	{
		i = _getch(); // �L�[���͑҂�
	} while ('q' != i);
	Title();
}
