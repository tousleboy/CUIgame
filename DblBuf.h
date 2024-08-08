#pragma once

#include <string>
#include <windows.h>

#define COL_BLACK   0x00
#define COL_DARK_BLUE   0x01
#define COL_DARK_GREEN  0x02
#define COL_DARK_CYAN    0x03
#define COL_DARK_RED    0x04
#define COL_DARK_MAGENTA    0x05
#define COL_DARK_YELLOW 0x06
#define COL_GRAY    0x07
#define COL_DARKGRAY    0x08
#define COL_BLUE    0x09
#define COL_GREEN   0x0A
#define COL_CYAN    0x0B
#define COL_RED 0x0C
#define COL_MAGENTA 0x0D
#define COL_YELLOW  0x0E
#define COL_WHITE   0x0F

#define COL_INTENSITY   0x08
#define COL_RED_MASK    0x04
#define COL_GREEN_MASK  0x02
#define COL_BLUE_MASK   0x01

class DblBuf {
	bool swapped;
	HANDLE hCons1;
	HANDLE hCons2;

public:
	DblBuf();
	~DblBuf();

	void setColor(int fg, int bg) const;
	void setCurPos(COORD pos) const;
	void write(const std::string& s) const;
	void swap();
	void clear();
};