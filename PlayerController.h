/*#include "MenoBohaviour.h"
#include "Bullet.h"

class PlayerController : public MenoBohaviour {
	using MenoBohaviour::MenoBohaviour;
public:
	void update() {
		if (GetAsyncKeyState(87) & 0x8000) {
			transform.Y--;
		}
		if (GetAsyncKeyState(83) & 0x8000) {
			transform.Y++;
		}
		if (GetAsyncKeyState(68) & 0x8000) {
			transform.X++;
		}
		if (GetAsyncKeyState(65) & 0x8000) {
			transform.X--;
		}
		if (GetAsyncKeyState(32) & 0x8000) {
			
		}
	}
	Bullet* shoot() {
		Bullet* b = new Bullet("-", transform.X + 1, transform.Y, 0, 0);
		return b;
	}
};*/

#include "MenoBohaviour.h"
#include "BulletController.h"

class PlayerController : public MenoBohaviour {
	using MenoBohaviour::MenoBohaviour;
public:
	void update() {
		COORD nextPos = transform;
		
		if (GetAsyncKeyState(87) & 0x8000) {
			if(transform.Y - 1 >= 0)transform.Y--;
		}
		if (GetAsyncKeyState(83) & 0x8000) {
			if(transform.Y <= 25)transform.Y++;
		}
		if (GetAsyncKeyState(68) & 0x8000) {
			if(transform.X <= 80)transform.X++;
		}
		if (GetAsyncKeyState(65) & 0x8000) {
			if(transform.X >= 0) transform.X--;
		}
		if (GetAsyncKeyState(32) & 0x8000) {
			shoot = true;
		}

		for (SHORT dx = -1; dx <= 1; dx++) {
			for (SHORT dy = -1; dy <= 0; dy++) {
				char next = buf->getChar(COORD{ nextPos.X + dx, nextPos.Y + dy });
				if (next == 'E') dead = true;
			}
		}
	}
};
