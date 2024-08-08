#pragma once

#include <string>
#include <windows.h>
#include "DblBuf.h"

class MenoBohaviour {
protected:
	std::string sprite;
	COORD transform;
	COORD offset;

public:
	MenoBohaviour(std::string str, int x, int y, int ox, int oy);
	virtual void start();
	virtual void update();
	virtual void render(const DblBuf& buf);
	void hoge();
};