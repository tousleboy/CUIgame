#pragma once

#include <string>
#include <vector>
#include <windows.h>
#include "DblBuf.h"

const int MB_SIZE = 100;

class MenoBohaviour {
protected:
	std::vector<std::string> sprite;
	DblBuf* buf;

public:
	MenoBohaviour(std::vector<std::string> sprite, int x, int y, int ox, int oy, DblBuf* buf);
	virtual void start();
	virtual void update();
	virtual void render();
	COORD transform;
	COORD offset;
	bool shoot;
	bool dead;
};