#include <string>
#include <Windows.h>
#include "MenoBohaviour.h"

#include <iostream>

MenoBohaviour::MenoBohaviour(std::string sprite_, int x_, int y_, int ox_, int oy_) {
	sprite = sprite_;
	transform.X = x_;
	transform.Y = y_;
	offset.X = ox_;
	offset.Y = oy_;
}

void MenoBohaviour::start() {

}

void MenoBohaviour::update() {

}

void MenoBohaviour::render(const DblBuf& buf) {
	COORD pos;
	pos.X = transform.X + offset.X;
	pos.Y = transform.Y + offset.Y;
	buf.setCurPos(pos);
	buf.write(sprite);
}

void MenoBohaviour::hoge() {
	std::cout << sprite << std::endl;
}