#ifndef BASICATTACK_H
#define BASICATTACK_H
#include "BaseAttack.h"
class BasicAttack : public BaseAttack {
public:
	inline BasicAttack() {
		Damage = 10;
		tag1 = "null";
		tag2 = "null";
		tag3 = "null";
		Name = "Sword Slash";
		TargetSelf = false;
		TargetTeam = false;
		Accuracy = 100;
	}
	
};





#endif //BASICATTACK_H
