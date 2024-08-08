#include <string>
#include <vector>
#include <Windows.h>
#include "MenoBohaviour.h"

#include <iostream>

MenoBohaviour::MenoBohaviour(std::vector<std::string> sprite_, int x_, int y_, int ox_, int oy_, DblBuf* buf_) {
	sprite = sprite_;
	transform.X = x_;
	transform.Y = y_;
	offset.X = ox_;
	offset.Y = oy_;
	buf = buf_;
	shoot = false;
	dead = false;
}

void MenoBohaviour::start() {

}

void MenoBohaviour::update() {

}

void MenoBohaviour::render() {
	COORD pos;

	pos.Y = transform.Y + offset.Y;
	for (std::string line : sprite) {
		pos.X = transform.X + offset.X;
		for (char c : line) {
			if (buf->isInScreen(pos)) {
				buf->setCurPos(pos);
				std::string s(" ");
				s[0] = c;
				buf->write(s);
			}
			pos.X++;
		}
		pos.Y++;
	}
}