#include "MenoBohaviour.h"

class PlayerController : public MenoBohaviour {
	using MenoBohaviour::MenoBohaviour;
public:
	void update() {
		transform.X++;
	}
};