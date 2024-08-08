#include "DblBuf.h"

DblBuf::DblBuf() {
	swapped = true;
	hCons1 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	hCons2 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hCons1);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hCons1, &info);
	SetConsoleCursorInfo(hCons2, &info);
}

DblBuf::~DblBuf()
{
	CloseHandle(hCons1);
	CloseHandle(hCons2);
}

void DblBuf::setColor(int fg, int bg = COL_BLACK) const {
	WORD attr = fg | (bg << 4);
	SetConsoleTextAttribute(swapped ? hCons1 : hCons2, attr);
}

void DblBuf::setCurPos(COORD pos) const {
	SetConsoleCursorPosition(swapped ? hCons1 : hCons2, pos);
}

void DblBuf::write(const std::string& str) const {
	DWORD len = str.size();
	WriteConsoleA(swapped ? hCons1 : hCons2, str.c_str(), len, &len, 0);
}

void DblBuf::swap() {
	if (swapped = !swapped) {
		SetConsoleActiveScreenBuffer(hCons2);
	}
	else {
		SetConsoleActiveScreenBuffer(hCons1);
	}
}

void DblBuf::clear() {
	DblBuf::write("\x1b[2J");
}