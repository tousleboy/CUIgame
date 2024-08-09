#ifndef _SCENE_H_
#define _SCENE_H_

/*
#include <windows.h>
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <io.h>
#include <stdio.h>
#include <conio.h>
*/

#include "PoolAllocator.h"
#include "BulletController.h"
const size_t MAX_ALLOCATE = 100;

class Scene {
public:
	Scene();
	~Scene();
	int score;

private:
	void Title();
	void Game();
	void Result();

};

#endif // _SCENE_H_
