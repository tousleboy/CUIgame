#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Scene.h"

void Scene::Title() {
	std::system("cls");
	std::cout << "Title" << std::endl;
	int i; //入力
	do
	{
		i = _getch(); // キー入力待ち
	} while ('q' != i && 's' != i);
	if ('s' == i) Game();
}
