#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Scene.h"

void Scene::Title() {
	std::system("cls");
	std::cout << "Title" << std::endl;
	int i; //“ü—Í
	do
	{
		i = _getch(); // ƒL[“ü—Í‘Ò‚¿
	} while ('q' != i && 's' != i);
	if ('s' == i) Game();
}
