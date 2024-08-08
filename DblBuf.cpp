#include <iostream>
#include "DblBuf.h"

DblBuf::DblBuf() {
	swapped = false;
	hCons1 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	hCons2 = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hCons1);

	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hCons1, &bufferInfo);
	bufferSize = bufferInfo.dwSize;
	buffer = new CHAR_INFO[bufferSize.X * bufferSize.Y];
	getContents();

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
	delete[] buffer;
}

void DblBuf::setColor(int fg, int bg) const {
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
		getContents();
		WriteConsoleA(hCons1, "\x1b[2J", 4, nullptr, 0);
	}
	else {
		SetConsoleActiveScreenBuffer(hCons1);
		getContents();
		WriteConsoleA(hCons2, "\x1b[2J", 4, nullptr, 0);
	}
}

void DblBuf::clear() {
	DblBuf::write("\x1b[2J");
}

char DblBuf::getChar(COORD pos) const {
	CHAR_INFO& charInfo = buffer[pos.Y * bufferSize.X + pos.X];
	return charInfo.Char.AsciiChar;
}

void DblBuf::getContents() {
	SMALL_RECT readRect = { 0, 0, bufferSize.X - 1, bufferSize.Y - 1 };
	ReadConsoleOutput(swapped ? hCons1 : hCons2, buffer, bufferSize, COORD{ 0, 0 }, &readRect);
}

bool DblBuf::isInScreen(COORD pos) const {
	return pos.X >= 0 && pos.Y >= 0 && pos.X < bufferSize.X && pos.Y < bufferSize.Y;
}