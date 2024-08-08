#include <iostream>
#include <conio.h>
#include "Scene.h"

void Scene::Result() {
	std::system("cls");
	std::cout << "Result" << std::endl;
	int i; //“ü—Í
	do
	{
		i = _getch(); // ƒL[“ü—Í‘Ò‚¿
	} while ('q' != i);
	Title();
}
