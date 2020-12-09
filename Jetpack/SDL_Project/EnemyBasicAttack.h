#ifndef ENEMYBASICATTACK_H
#define ENEMYBASICATTACK_H
#include "BaseAttack.h"
class EnemyBasicAttack : public BaseAttack {
public:
	inline EnemyBasicAttack() {
		Damage = 20;
		tag1 = "null";
		tag2 = "null";
		tag3 = "null";
		Name = "Overhead Axe Slash";
		TargetSelf = false;
		TargetTeam = false;
		Accuracy = 60;
	}

};





#endif //ENEMYBASICATTACK_H
