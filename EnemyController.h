#pragma once

#include <iostream>
#include <random>
#include "MenoBohaviour.h"

std::random_device rd; // �n�[�h�E�F�A������������g���ăV�[�h���擾
std::mt19937 gen(rd()); // �����Z���k�E�c�C�X�^�G���W���̃C���X�^���X
std::uniform_int_distribution<> dis(-1, 1); // -1����1�܂ł̐����̈�l���z

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