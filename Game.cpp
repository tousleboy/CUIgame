#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Scene.h"

void Scene::Game() {
	std::system("cls");
	// テンキー or wasdで@マークが移動するだけのサンプル
	// サンプルなので消しても大丈夫です。
	int x = 0; // X座標
	int y = 0; // Y座標
	int i; // キー入力値
	do
	{
		printf("\x1b[%d;%dH@", y, x); // 今の座標に'@'表示
		i = _getch(); // キー入力待ち
		printf("\x1b[%d;%dH ", y, x); // 前の座標に' '表示
		// キー入力で座標更新
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
	} while ('q' != i); // 'q'キーで終了
	Result();
}
