#ifndef BASICATTACK_H
#define BASICATTACK_H
#include "BaseAttack.h"
class BasicAttack : public BaseAttack {
public:
	float Damage = 10;
	std::string tag1 = "null";
	std::string tag2 = "null";
	std::string tag3 = "null";
	std::string Name = "Sword Slash";
	bool TargetSelf = false;
	bool TargetTeam = false;
	float Accuracy = 100;
};





#endif //BASICATTACK_H
