#include <iostream>
#include <conio.h>
#include "Scene.h"

void Scene::Result() {
	std::system("cls");
	std::cout << "Result" << std::endl;
	int i; //入力
	do
	{
		i = _getch(); // キー入力待ち
	} while ('c' != i);
	Title();
}
