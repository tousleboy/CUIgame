#pragma once

#include "MenoBohaviour.h"

class EnemyController : public MenoBohaviour {
	using MenoBohaviour::MenoBohaviour;
public:
	void update() {
		COORD nextPos = transform;
		nextPos.Y += 1;
		char next = buf->getChar(nextPos);
		if (transform.Y >= 0) {
			transform.Y--;
		}
		else dead = true;
	}
};