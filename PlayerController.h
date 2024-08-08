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
		nextPos.X += 1;
		char next = buf->getChar(nextPos);
		
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
			shoot = true;
		}
	}
};
