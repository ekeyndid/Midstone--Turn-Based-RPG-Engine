#ifndef BASEATTACK_H
#define BASEATTACK_H
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdlib.h>
class BaseAttack //base class for attacks any enemy or player can perform.
{
protected:
	float Damage; //The damage of the attack
	float Accuracy; // Accuracy of attack
	std::string tag1; //the tags of the attacks, such as Bleed, or Bypass defense.
	std::string tag2; //Tags will be displayed somehow (maybe) in the future
	std::string tag3; 
	std::string Name; // name
	bool TargetSelf; // Will it target self? or no?
	bool TargetTeam; // Will it target team? or no?
	

	




};

#endif
