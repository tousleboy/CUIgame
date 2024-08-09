#pragma once

#include <iostream>
#include <random>
#include "MenoBohaviour.h"

std::random_device rd; // ハードウェア乱数生成器を使ってシードを取得
std::mt19937 gen(rd()); // メルセンヌ・ツイスタエンジンのインスタンス
std::uniform_int_distribution<> dis(-1, 1); // -1から1までの整数の一様分布

class EnemyController : public MenoBohaviour {
	using MenoBohaviour::MenoBohaviour;
public:
	void update() {
		int x_ = dis(gen);
		int y_ = dis(gen);
		COORD nextPos = transform;
		nextPos.X += x_;
		nextPos.Y += y_;
		if (nextPos.X < 0 || nextPos.X > 80) {
			transform.X -= x_;
		}
		else {
			transform.X += x_;
		}
		if (nextPos.Y < 0 || nextPos.Y > 25) {
			transform.Y -= y_;
		}
		else {
			transform.Y += y_;
		}
		for (SHORT dx = -1; dx <= 1; dx++) {
			char next = buf->getChar(COORD{ nextPos.X + dx, nextPos.Y });
			if (next == 'o') dead = true;
		}
		
		
	}
};