#ifndef BASEATTACK_H
#define BASEATTACK_H
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdlib.h>
class BaseAttack
{
public:
	float Damage;
	float Accuracy;
	std::string tag1;
	std::string tag2;
	std::string tag3;
	//enum Effects; // ask about this one
	std::string Name;
	bool TargetSelf;
	bool TargetTeam;




};

#endif
